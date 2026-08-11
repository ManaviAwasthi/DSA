class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        int n=v.size(); 
        unordered_map <int,int> m; //value->index
        for (int i=0; i<n; i++){
            int j=target-v[i];
            if (m.find(j)!=m.end()){
                return {i,m[j]};
            }
            m[v[i]]=i;
        }
        return {};
    }
};