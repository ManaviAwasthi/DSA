class Solution {
public:
    int passwordStrength(string password) {
        vector <int> vis(256,0);
        for (char c: password){
            vis[c]=1;
        }
        int ans=0;
        char c;
        for (int i=0; i<256; i++){
            if (vis[i]) {
                c=i;
                if (c>='a' && c<='z'){
                    ans++;
                }
                else if (c>='A' && c<='Z'){
                    ans+=2;
                }
                else if (c>='0' && c<='9'){
                    ans+=3;
                }
                else {
                    ans+=5;
                }
            }
        }
        return ans;
    }
};