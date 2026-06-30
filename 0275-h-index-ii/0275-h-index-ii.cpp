class Solution {
public:
    int hIndex(vector<int>& v) {
        int n=v.size();
        int l=0,r=n-1,ans=0;
        while (l<=r){
            int mid= l+(r-l)/2;
            if (v[mid]>=n-mid){
                ans=n-mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};