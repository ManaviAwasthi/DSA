class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map <int, int> m;
        int l=0, r=0, res=0;
        while (r<n){
            m[nums[r]]++;
            while (m[nums[r]]>k){
                m[nums[l]]--;
                l++;
            }
            res=max(r-l+1,res);
            r++;
        }
        return res;
    }
};