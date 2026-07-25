class Solution {
public:
    int evalRPN(vector<string>& v) {
        int n=v.size();
        stack <int> st;
        int ans;
        for (int i=0; i<n; i++){
            auto c= v[i];
            if ((c=="+" || c=="-" || c=="*" || c=="/") && st.size()>=2){
                int second= st.top(); st.pop();
                int first= st.top(); st.pop();
                if (c=="+"){
                    ans=first+second;
                }
                else if (c=="-"){
                    ans=first-second;
                }
                else if (c=="*"){
                    ans=first*second;
                }
                else if (c=="/"){
                    ans=first/second;
                }
                st.push(ans);
            }
            else {
                int m= stoi(c);
                st.push(m);
            }
        }
        if (!st.empty()){
            ans=st.top();
        }
        return ans;
    }
};