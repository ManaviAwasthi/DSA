class Solution {
public:
    int countCollisions(string s) {
        int n=s.size();
        int l=0;
        while(l<n && s[l]=='L'){
            l++;
        }
        int rt=n-1;
        while (rt>=0 && s[rt]=='R'){
            rt--;
        }
        int ans=0;
        for (int i=l; i<=rt; i++){
            if(s[i]!='S') ans++;
        }
        return ans;
    }
};