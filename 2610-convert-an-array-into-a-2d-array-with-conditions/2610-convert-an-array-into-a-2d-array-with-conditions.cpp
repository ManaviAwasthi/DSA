class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<vector<int>> ans;
        for (int x : nums) {
            int row = mp[x]++;
            if (row == ans.size())
                ans.push_back({});

            ans[row].push_back(x);
        }

        return ans;
    }
};