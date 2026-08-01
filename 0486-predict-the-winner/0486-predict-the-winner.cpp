class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector <vector<int>> dp(n, vector <int> (n,0)); 
        // dp stores final score dfference for both subarrays, left/right pickups
        for (int i=0; i<n; i++){
            dp[i][i]=nums[i]; //when only single element is left
        }
        for (int len=2; len<=n; len++){//subarray len
            for (int l=0; l+len-1<n; l++){
                int r=l+len-1;
                dp[l][r]=max(nums[l]-dp[l+1][r],nums[r]-dp[l][r-1]);

            }
        }
        //now if the max score difference between subarray index 0 to n-1 is +ve/0, player one wins
        if (dp[0][n-1]<0) return false;
        return true;
    }
};