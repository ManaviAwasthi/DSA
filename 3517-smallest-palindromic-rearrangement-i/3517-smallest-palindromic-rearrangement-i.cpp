class Solution {
public:
    string smallestPalindrome(string s) {
        int n= s.length();
        int mid= n/2;
        vector <int> freq (26,0);
        for (int i=0; i<mid; i++){
            freq[s[i]-'a']++;
        }
        int idx=0;
        for (int i=0; i<26; i++){
            while (freq[i]--){
                s[idx]=i+'a';
                idx++;
            }
        }
        for (int i=0; i<mid; i++){
            s[n-i-1]=s[i];
        }
        return s;
    }
};