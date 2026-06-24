class Solution {
public:
    int repeatedNTimes(vector<int>& v) {
        int n=v.size();
        for (int i=0; i<n-2; i++){
            if (v[i]==v[i+1] || v[i]==v[i+2]){
                return v[i];
            }
        }
        return v.back();
    }
};