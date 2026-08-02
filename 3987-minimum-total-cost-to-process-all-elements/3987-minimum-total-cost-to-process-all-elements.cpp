class Solution {
    const int MOD = 1e9 + 7;
public:
    int minimumCost(vector<int>& nums, int k) {
        int n= nums.size();
        long long cost= 0;
        long long res= k;
        long long op= 0;

        for (int i=0; i<n; i++) {

            if (res>=nums[i]) {
                res-=nums[i];
            }
            else {
                long long need = (nums[i]-res+k-1)/k;
                __int128 add = (__int128)need * (2 * op + need + 1) / 2;
                cost = (cost + (long long)(add % MOD)) % MOD;
                op += need;
                res += need * k;
                res -= nums[i];
            }
        }

        return cost % MOD;
    }
};