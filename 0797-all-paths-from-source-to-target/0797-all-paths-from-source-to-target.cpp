class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& v) {
        int n=v.size();
        vector <vector <int>> adj(n);
        for (int i=0; i<n; i++){
            for (auto j: v[i]){
                adj[i].push_back(j);
            }
        }
        vector <vector <int>> res;
        queue <vector <int>> q;
        vector <int> path;
        q.push({0});
        while (!q.empty()){
            path = q.front();
            q.pop();
            int node=path.back();
            if (node==n-1){
                res.push_back(path);
            }
            for (auto it: adj[node]){
                vector <int> temp= path;
                temp.push_back(it);
                q.push(temp);
            }
        }
        return res;
    }
};