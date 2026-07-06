class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& v) {
        int n= v.size();
        sort (v.begin(),v.end());
        int low=v[0][0];
        int high=v[0][1];
        int ans=0;
        for (int i=1; i<n; i++){
            if (v[i][1]>high){
                if (v[i][0]==low) ans++;
                low=v[i][0];
                high=v[i][1];
            }
            else{
                ans++;
            }
        }
        return n-ans;
    }
};