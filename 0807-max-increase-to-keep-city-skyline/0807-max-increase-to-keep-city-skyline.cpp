class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& v) {
        int n=v.size();
        vector <int> row(n,0);
        vector <int> col(n,0);
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                row [i]=max(row[i], v[i][j]);
                col [j]=max(col[j], v[i][j]);
            }
        }
        int ans=0;
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                ans+= min(row[i],col[j])-v[i][j];
            }
        }
        return ans;
    }
};