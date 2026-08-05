class Solution {
public:
    int findMin(vector<int>& nums) {
        int mn= INT_MAX;
        int n=nums.size();
        for (int i=0; i<n; i++){
            mn=min(mn,nums[i]);
        }
        return mn;
    }
};