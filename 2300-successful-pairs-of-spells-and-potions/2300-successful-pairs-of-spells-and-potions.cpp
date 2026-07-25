class Solution {
public:
    vector<int> successfulPairs(vector<int>& sp, vector<int>& ps, long long x) {
        int n=sp.size();
        int m=ps.size();
        sort (ps.begin(),ps.end());
        vector <int> ans (n,0);

        for (int i=0; i<n; i++){
            int start=0;
            int end= m-1;
            long long tar = (x+sp[i]-1)/sp[i];
            int index=-1;
            int mid;
            while (start<=end){
                mid= start + (end-start)/2;
                if (ps[mid]>=tar){
                    index=mid;
                    end=mid-1;
                }
                else {
                    start=mid+1;
                }
            }
            if (index!=-1){
                ans[i]=m-index;
            }
        } 
        return ans;
    }
};