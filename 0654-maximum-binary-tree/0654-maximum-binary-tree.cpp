class Solution {
private: 
    TreeNode* Solve (vector <int> & nums, int l, int r){
        if (l>r) return nullptr;

        int mx=l;
        for (int i=l; i<=r; i++){
            if (nums[i]>nums[mx]){
                mx=i;
            }
        }

        TreeNode* node= new TreeNode(nums[mx]);
        node->left=Solve(nums,l,mx-1);
        node->right=Solve(nums,mx+1,r);

        return node;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
        return Solve (nums,0,n-1);
    }
};