class Solution {
public:
    int partitionString(string s) {
        int n=s.length();
        unordered_map <char,int> m;
        int cnt=1;
        for (int i=0; i<n; i++){
            char c= s[i];
            if (m.find(c)!=m.end()){
                cnt++;
                m.clear();
            }
            m[c]=i;
        }
        return cnt;
    }
};