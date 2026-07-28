class Solution {
public:
    string convert(string s, int r) {
        int n=s.length();
        if (r==1 || r>=n){
            return s;
        }
        vector <vector <char>> rows(r);
        int pos=0;
        int d;
        for (int i=0; i<n;i++){
            if (pos==0){
                d=1;
            }
            else if (pos==r-1){
                d=-1;
            }
            rows[pos].push_back(s[i]);
            pos+=d;
        }
        string res;
        res.reserve(n);
        for (auto &it: rows){
            for (char c: it){
                res.push_back(c);
            }
        }
        return res;
        
    }
};