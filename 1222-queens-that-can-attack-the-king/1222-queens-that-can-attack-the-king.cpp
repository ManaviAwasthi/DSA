class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector <int> dr={0,1,1,1,0,-1,-1,-1};
        vector <int> dc={1,1,0,-1,-1,-1,0,1};

        vector <vector<int>> q(8, vector <int> (8,0));
        int n=queens.size();
        for (int i=0;i<n;i++){
            int r=queens[i][0];
            int c=queens[i][1];
            q[r][c]=1;
        }

        int kr=king[0];
        int kc=king[1];
        vector <vector <int>> ans;

        for (int i=0;i<8;i++){
            int nr=kr+dr[i];
            int nc=kc+dc[i];

            while (nr>=0 && nr<8 && nc>=0 && nc<8){
                if (q[nr][nc]){
                    ans.push_back({nr,nc});
                    break;
                }
                nr=nr+dr[i];
                nc=nc+dc[i];
            }
        }
        return ans;
    }
};