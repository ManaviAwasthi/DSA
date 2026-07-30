class Solution {
public:
    vector<int> minOperations(string s) {
        int n=s.length();
        vector <int> ans;
        vector <int> pos;
        for (int i=0; i<n; i++){
            if (s[i]=='1'){
                pos.push_back(i);
            }
        }
        for (int i=0; i<n; i++){
            int sum=0;
            for (int idx: pos){
                int diff= abs(i-idx);
                sum+=diff;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};