class Solution {
public:
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        int x = util(root);
        return res;
    }
    int util(TreeNode * root){
        if(root== NULL){
            return 0;
        }
        int rightval = util(root->right);
        int leftval = util(root->left);
        res = max(root->val, max(root->val+ leftval, max(root->val + rightval, max(res, root->val + leftval + rightval))));
        return max(root->val, max(root->val + leftval, root->val + rightval));
    }
};