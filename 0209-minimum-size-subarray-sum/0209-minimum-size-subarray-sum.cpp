class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0; 
        int r=0;
        int sum=0;
        int len=INT_MAX;
        while (r<n){
            sum+=nums[r];
            r++;
            while (sum>=target){
                sum-=nums[l];
                len=min(len,r-l);
                l++;
            }
        }
        if (len==INT_MAX) return 0;
        return len;
    }
};