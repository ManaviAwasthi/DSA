class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n= nums.size();
        vector <int> ans(n,0);
        int sum=0;
        int tsum=0;
        for(int i=0;i<n;i++){
            tsum+=nums[i];
        }
        
        for(int i=0;i<n;i++){
            if (i!=0)sum+=nums[i-1];
            ans[i]= abs(sum - (tsum-nums[i]-sum));
        }
        return ans;
    }
};