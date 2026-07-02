class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& v, int h) {
        int m = v.size();
        int n = v[0].size();

        if (v[0][0] == 1) h--;

        priority_queue<vector<int>> pq;
        pq.push({h, 0, 0});

        vector<vector<int>> best(m, vector<int>(n, -1));
        best[0][0] = h;

        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,1,0,-1};

        while (!pq.empty()) {
            vector<int> tp = pq.top();
            pq.pop();

            int hl = tp[0];
            int r = tp[1];
            int c = tp[2];

            if (r == m-1 && c == n-1) return true;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {

                    int nh = hl;                  // NEW
                    if (v[nr][nc] == 1)
                        nh--;

                    if (nh > 0 && nh > best[nr][nc]) {   // NEW
                        best[nr][nc] = nh;
                        pq.push({nh, nr, nc});
                    }
                }
            }
        }
        return false;
    }
};