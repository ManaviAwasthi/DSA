class Solution {
public:
    int repeatedNTimes(vector<int>& v) {
        int n=v.size();
        unordered_map<int,int> m;
        for (int i=0; i<n; i++){
            m[v[i]]++;
            if (m[v[i]]>1) return v[i];
        }
        return -1;
    }
};