class Solution {
public:
    TreeNode* util(TreeNode* root){
        if(root == NULL){
            return NULL;
        }
        TreeNode *r = util(root->right);
        TreeNode *l = util(root->left);
        root->left = NULL;
        if(l && r){
            root->right = l;
            TreeNode *temp = l;
            while(temp->right)
                temp = temp->right;
            temp->right = r;
        }
        else if(l){
            root->right = l;
        }
        else if(r){
            root->right = r;
        }
        return root;
    }
    void flatten(TreeNode* root) {
       root = util(root);
    }
};