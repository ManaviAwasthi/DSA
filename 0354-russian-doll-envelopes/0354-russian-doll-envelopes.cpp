class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& v) {
        sort (v.begin(),v.end(), [](const vector <int> &a, const vector <int> &b){
            if (a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        vector <int> ans;
        for (auto &it: v){
            int ht= it[1];
            auto itr= lower_bound(ans.begin(),ans.end(),ht);
            if (itr==ans.end()) ans.push_back(ht);
            else *itr=ht;
        }
        return ans.size();
    }
};