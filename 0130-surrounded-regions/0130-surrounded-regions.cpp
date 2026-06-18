class Solution {
    void dfs(int r,int c, vector <vector <char>> &v, vector <vector <int>> &vis){
        int m=v.size();
        int n=v[0].size();
        vis[r][c]=1;
        vector <int> dr={-1,0,1,0};
        vector <int> dc={0,1,0,-1};

        for (int i=0; i<4; i++){
            int nr=r+dr[i];
            int nc=c+dc[i];

            if (nr>=0 && nr<m && nc>=0 && nc<n && v[nr][nc]=='O' && !vis[nr][nc]){
                dfs(nr,nc,v,vis);
            }
        }
    }
public:
    void solve(vector<vector<char>>& v) {
        int m=v.size();
        int n=v[0].size();
        vector <vector <int>> vis(m, vector <int> (n,0));

        for (int i=0;i<m;i++){
            for (int j=0; j<n; j++){
                if (i==0||i==m-1||j==0||j==n-1){
                    if (v[i][j]=='O')
                    dfs(i,j,v,vis);
                }
            }
        }

        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (v[i][j]=='O' && !vis[i][j]){
                    v[i][j]='X';
                }
            }
        }
        
    }
};