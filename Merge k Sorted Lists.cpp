/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct compareNode {
      bool operator()(ListNode* const & p1, ListNode* const & p2){
           return p1->val > p2->val;
      }  
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *tail, *head = new ListNode(0);
        tail = head;
        priority_queue<ListNode*, vector<ListNode*>, compareNode> minHeap;
        for (vector<ListNode *>::iterator it = lists.begin(); it != lists.end(); ++it){
            if (*it)
            minHeap.push(*it);
        }
        while(!minHeap.empty()){
            tail->next = minHeap.top();
            minHeap.pop();
            tail = tail->next;
            if(tail && tail->next){
                minHeap.push(tail->next);
            }
        }
        return head->next;
    }
};