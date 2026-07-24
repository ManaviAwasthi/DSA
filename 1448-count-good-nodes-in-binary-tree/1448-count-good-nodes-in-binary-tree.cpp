class Solution {
private: 
    int dfs (TreeNode* root, int maxi){
        if (root==nullptr) return 0;
        int count=0;
        if (root->val>=maxi) {
            count++;
        }
        maxi=max(maxi,root->val);
        count+=dfs(root->left, maxi);
        count+=dfs(root->right,maxi);

        return count;
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};