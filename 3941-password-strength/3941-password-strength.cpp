class Solution {
public:
    int passwordStrength(string password) {
        unordered_set <char> st;
        int n=password.length();
        for (int i=0; i<n; i++){
            st.insert(password[i]);
        }
        int ans=0;
        for (char c: st){
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
        return ans;
    }
};