class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.length();
        vector <int> occ(26);
        vector <int> vis(26,0);

        for (int i=0; i<n; i++){
            occ[s[i]-'a']=i;
        }
        string ans="";

        for (int i=0; i<n; i++){
            if (vis[s[i]-'a']) continue;
            while (!ans.empty() && s[i]<ans.back() && occ[ans.back()-'a']>i){
                vis[ans.back()-'a']=0;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            vis[s[i]-'a']=1;
        }
        return ans;
    }
};