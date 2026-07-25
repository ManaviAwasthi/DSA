class Solution {
public:
    int evalRPN(vector<string>& v) {
        int n=v.size();
        stack <int> st;
        for (int i=0; i<n; i++){
            auto c= v[i];
            if ((c=="+" || c=="-" || c=="*" || c=="/") && st.size()>=2){
                int second= st.top(); st.pop();
                int first= st.top(); st.pop();
                if (c=="+"){
                    st.push(first+second);
                }
                else if (c=="-"){
                    st.push(first-second);
                }
                else if (c=="*"){
                    st.push(first*second);
                }
                else if (c=="/"){
                    st.push(first/second);
                }
            }
            else {
                int m= stoi(c);
                st.push(m);
            }
        }
        return st.top();
    }
};