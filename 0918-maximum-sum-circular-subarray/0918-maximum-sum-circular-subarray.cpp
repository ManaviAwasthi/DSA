class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int cmax=0;
        int mxsum=nums[0];
        int cmin=0;
        int mnsum=nums[0];
        for (int i=0; i<n; i++){
            cmax=max(nums[i],cmax+nums[i]);
            mxsum=max(mxsum,cmax);
            cmin=min(nums[i],cmin+nums[i]);
            mnsum = min(mnsum, cmin);
            sum+=nums[i];
        }
        if (mnsum == sum){
            return mxsum;
        }

        return max(mxsum, sum - mnsum);
    }
};