class Solution {
public:
    int minimumDeletions(vector<int>& a) {
        int n=a.size(),x=0,y=0;
        for(int i=1;i<n;i++){
            if(a[i]<a[x]) x=i;
            if(a[i]>a[y]) y=i;
        }
        int l=min(x,y),r=max(x,y);
        return min({r+1,n-l,l+1+n-r});
    }
};