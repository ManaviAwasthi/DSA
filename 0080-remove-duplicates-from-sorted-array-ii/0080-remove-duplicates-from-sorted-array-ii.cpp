class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map <int, int> m;
        int n=nums.size();
        for (int i=0; i<n; i++){
            m[nums[i]]++;
            if (m[nums[i]]>2) nums[i]=INT_MAX;
        }
        sort (nums.begin(),nums.end());
        int k=n;
        for (int i=0; i<n; i++){
            if (nums[i]==INT_MAX) {
                k=i;
                break;
            }
        }
        return k;
    }
};