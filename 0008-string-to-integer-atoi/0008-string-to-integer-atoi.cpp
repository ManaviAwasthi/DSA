class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        int itr=0;
        int sign=1;
        int ans=0;
        while (itr<n && s[itr]==' '){
            itr++;
        }
        if (itr<n && (s[itr]=='+'||s[itr]=='-')){
            if (s[itr]=='-')
                sign=-1;
            itr++;
        }
        for (int i=itr; i<n; i++){
            if (!(s[i]>='0' && s[i]<='9')){
                break;
            }
            int digit = s[i]-'0';
            if (ans > INT_MAX / 10 ||
               (ans==INT_MAX/10 && digit>7)) {
                return sign == 1? INT_MAX : INT_MIN;
            }
            ans=ans*10+digit;
        }
       return sign*ans; 
    }
};