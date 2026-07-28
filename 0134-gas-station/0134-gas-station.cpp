class Solution {
public:
    int canCompleteCircuit(vector<int>& g, vector<int>& c) {
        int n=g.size();
        int tg=0;
        int tc=0;
        for (int i=0; i<n; i++){
            tg+=g[i];
            tc+=c[i];
        }
        if (tg<tc){
            return -1;
        }
        int start =0;
        int tank=0;
        for (int i=0; i<n; i++){
            tank+=g[i]-c[i];
            if (tank<0){
                start=i+1;
                tank=0;
            }
        }
        return start;
    }
};