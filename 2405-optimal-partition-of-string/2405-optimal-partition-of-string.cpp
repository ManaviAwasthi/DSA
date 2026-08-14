class Solution {
public:
    int partitionString(string s) {
        int n=s.length();
        unordered_set <char> st;
        int cnt=1;
        for (int i=0; i<n; i++){
            char c= s[i];
            if (st.count(c)){
                cnt++;
                st.clear();
            }
            st.insert(c);
        }
        return cnt;
    }
};