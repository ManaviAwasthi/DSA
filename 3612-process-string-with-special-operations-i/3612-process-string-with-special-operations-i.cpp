class Solution {
public:
    string processStr(string s) {
        string s1="";
        for (char c: s){
            if (c-'a'>=0 && c-'a'<26){
                s1+=c;
            }
            else if (c=='*'){
                if (!s1.empty()){
                    s1.pop_back();
                }
            }
            else if (c=='#'){
                s1+=s1;
            }
            else if (c=='%'){
                reverse(s1.begin(),s1.end());
            }
        }
        return s1;
    }
};