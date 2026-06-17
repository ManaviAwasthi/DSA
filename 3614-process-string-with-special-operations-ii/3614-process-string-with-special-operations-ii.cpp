class Solution {
public:
    char processStr(string s, long long k) {
        int n=s.length();
        long long len=0;
        vector <long long> inlen(n);
        for (int i=0; i<n; i++){
            char c= s[i];
            if (c>='a' && c<='z'){
                len++;
            }
            else if (c=='*'){
                if (len) len--;
            }
            else if (c=='#'){
                len=2*len;
            }
            inlen[i]=len;
        }

        if (k>=len) return '.';
        
        for (int i=n-1; i>=0; i--){
            long long init;
            char c=s[i];
            if (i==0){
                init=0;
            }
            else {
                init= inlen[i-1];
            }

            if (c>='a' && c<='z'){
                if (k==init) return c;
            }
            else if (c=='#'){
                k=k%init;
            }
            else if (c=='%'){
                k=init-1-k;
            }
        }
        return '.';
    }
};