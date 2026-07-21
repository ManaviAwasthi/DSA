class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int one= 0; 
        int n= s.length(); 
        for(int i=0; i<n; i++) {
            if(s[i] == '1') {
                one++;
            }
        } 
        
        int zero = -1;
        int ans= 0; 
        int i = 0; 
        while(i < n) {
            int j = i; 
            while(j < n && s[j] == s[i]) j++; 
            int len = j - i; 

            if(s[i] == '0') {
                if(zero!=-1) {
                    ans = max(ans,zero + len );
                } 
                zero=len; 
            }
            i = j; 
        }
        return one+ans; 
    }
};