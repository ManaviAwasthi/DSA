class Solution {
public:
    int firstStableIndex(vector<int>& a,int k){
        int n=a.size();
        vector<int>s(n);
        s[n-1]=a[n-1];

        for(int i=n-2;i>=0;i--){
            s[i]=min(a[i],s[i+1]);
        }
        int mx=a[0];

        for(int i=0;i<n;i++){
            mx=max(mx,a[i]);
            if(mx-s[i]<=k)return i;
        }
        
        return -1;
    }
};