class Solution {
public:
    string removeStars(string s) {
      int n=s.length();
      stack <char> st;
      for (int i=0; i<n; i++){
        if (s[i]>='a' && s[i]<='z'){
            st.push(s[i]);
        }
        else if (s[i]=='*'){
            st.pop();
        }
      } 

      string ans="";
      while (!st.empty()){
        char c= st.top();
        st.pop();
        ans+=c;
      }
      reverse (ans.begin(), ans.end()); 
      return ans;
    }
};