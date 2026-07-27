class Solution {
public:
    int nearestExit(vector<vector<char>>&v, vector<int>& en) {
        int m=v.size();
        int n=v[0].size();
        vector <vector<int>> vis (m, vector <int> (n,0));
        vis[en[0]][en[1]]=1;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (v[i][j]=='+'){
                    vis[i][j]=1;
                }
            }
        }
        queue <pair <pair <int,int>, int>> q;
        q.push({{en[0],en[1]},0});
        vector <int> dr= {-1,0,1,0};
        vector <int> dc= {0,1,0,-1};

        while (!q.empty()){
            int r= q.front().first.first;
            int c= q.front().first.second;
            int d= q.front().second;
            q.pop();

            for (int i=0; i<4; i++){
                int nr= r+dr[i];
                int nc= c+dc[i];

                if (nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc]){
                    if (nr==0 || nr==m-1|| nc==0 || nc==n-1){
                        return d+1;
                    }
                    vis[nr][nc]=1;
                    q.push({{nr,nc},d+1});
                }
            }
        }
        return -1;
    }
};