class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map <int, int> mp;
        int z=0;
        int one=0;
        int len=0;
        mp[0]=-1;
        for (int i=0; i<n; i++){
            if (nums[i]==0) z++;
            else one++;
            int diff= z-one;
            if (mp.find(diff)!=mp.end()){
                len=max(len, i-mp[diff]);
            }
            else{
                mp[diff]=i;
            }
        }
        return len;
    }
};