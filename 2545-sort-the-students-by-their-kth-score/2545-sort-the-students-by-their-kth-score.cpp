class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& v, int k) {
        int m=v.size();
        for (int i=0; i<m; i++){
            int maxi=i;
            for (int j=i+1; j<m; j++){
                if (v[j][k]>v[maxi][k]){
                    maxi=j;
                }
            }
            swap(v[i],v[maxi]);
        }
        return v;
    }
};