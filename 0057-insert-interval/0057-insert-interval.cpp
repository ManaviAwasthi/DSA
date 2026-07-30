class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& in) {
        int n=v.size();
        vector <vector <int>> ans;
        int i=0;
        while (i<n && v[i][1]<in[0]){
            ans.push_back(v[i]);
            i++;
        }
        while (i<n && v[i][0]<=in[1]){
            in[0]=min(in[0],v[i][0]);
            in[1]=max(in[1],v[i][1]);
            i++;
        }
        ans.push_back(in);
        while (i<n){
            ans.push_back(v[i]);
            i++;
        }
        return ans;
    }
};