class Solution {
public:
    vector<int> minOperations(string s) {
        int n=s.length();
        vector <int> ans(n,0);
        int balls=0;
        int ops=0;
        for (int i=0; i<n; i++){
            ans[i]+=ops;
            if (s[i]=='1'){
                balls++;
            }
            ops+=balls;
        }
        balls=0;
        ops=0;
        for (int i=n-1; i>=0; i--){
            ans[i]+=ops;
            if (s[i]=='1'){
                balls++;
            }
            ops+=balls;
        }

        return ans;
    }
};