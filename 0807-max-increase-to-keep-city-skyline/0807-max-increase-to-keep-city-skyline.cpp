class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& v) {
        int n=v.size();
        vector <vector <int>> maxi(n, vector <int> (n,0));
        int mx=0;
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                mx=max(mx,v[i][j]);
            }
            for (int j=0; j<n; j++){
                maxi[i][j]=mx;
            }
            mx=0;
        }
        for (int j=0; j<n; j++){
            for (int i=0; i<n; i++){
                mx=max(mx,v[i][j]);
            }
            for (int i=0; i<n; i++){
                maxi[i][j] = min(maxi[i][j], mx);
            }
            mx=0;
        }
        int ans=0;
        for (int i=0; i<n; i++){
            if (v[i][i]<maxi[i][i]){
                ans+=maxi[i][i]-v[i][i];
            }
        }
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (i!=j){
                    if (v[i][j]<maxi[i][j]){
                        ans+=maxi[i][j]-v[i][j];
                    }
                }
            }
        }
        return ans;
    }
};