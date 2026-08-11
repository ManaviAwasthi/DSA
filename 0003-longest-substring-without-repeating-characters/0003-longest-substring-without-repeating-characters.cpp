class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n= s.size();
        unordered_map <char, int> m;
        int l=0, r=0, mlen=0;
        while (r<n){
            char c= s[r];
            if (m.find(c)!=m.end()){
                if (m[c]>=l){
                    l=m[c]+1;
                }
                
            }
            mlen= max(r-l+1,mlen);
            m[c]=r;
            r++;
        }
        return mlen;
    }
};