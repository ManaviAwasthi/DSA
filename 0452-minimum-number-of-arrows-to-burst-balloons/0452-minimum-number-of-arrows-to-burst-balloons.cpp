class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        int n=p.size();
        sort (p.begin(),p.end());
        long long end= p[0][1];
        int count=1;
        for (int i=1; i<n; i++){
            if (p[i][0]<=end){
                end=min((long long) p[i][1],end);
            }
            else {
                end=p[i][1];
                count++;
            }
        }
        return count;
    }
};