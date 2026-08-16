class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int n=lights.size();
        int mx=0;
        for (int i=0; i<n; i++){
            mx=max(mx,lights[i]);
        }
        n=arrivalTime.size();
        int ans=0;
        for (int i=0; i<n; i++){
            int r=arrivalTime[i]%period;
            if (r<mx) {
                ans=max(ans,0);
            }
            else {
                ans=max(ans,period-r);
            }
        }
        return ans;
    }
};