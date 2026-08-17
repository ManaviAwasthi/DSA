class Solution {
public:
    int maxWidthRamp(vector<int>& v) {
        int n = v.size();
        stack<int> st;
        int ans = 0;
        for (int i=0; i<n; i++) {
            if (st.empty() || v[i] < v[st.top()]) {
                st.push(i);
            }
        }
        for (int j=n-1; j>0; j--) {
            while (!st.empty() && v[st.top()]<=v[j]) {
                ans=max(ans, j-st.top());
                st.pop();
            }
        }
        return ans;
    }
};