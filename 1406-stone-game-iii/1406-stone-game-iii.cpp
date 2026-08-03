class Solution {
public:
    string stoneGameIII(vector<int>& nums) {
        int n=nums.size();
        vector <int> dp (3,0);
        for (int i=n-1; i>=0; i--){
            int t1= nums[i]-dp[(i+1)%3];
            int t2= INT_MIN;
            if (i+1<n) t2= nums[i]+nums[i+1]-dp[(i+2)%3];
            int t3=INT_MIN;
            if (i+2<n) t3= nums[i]+nums[i+1]+nums[i+2]-dp[(i+3)%3];
            dp[i%3]=max({t1,t2,t3});
        }
        int ans=dp[0];
        if (ans>0) return "Alice";
        if (ans<0) return "Bob";
        return "Tie"; 
    }
};