class Solution {
public:
    int numOfMinutes(int n, int head, vector<int>& man, vector<int>& in) {
        vector <vector <int>> adj(n);
        for (int i=0; i<man.size(); i++){
            if (man[i]!=-1){
                adj[man[i]].push_back(i);
            }
        }
        queue <pair<int,int>> q;
        q.push({head,0});
        int ans=0;
        while (!q.empty()){
            int emp=q.front().first;
            int time=q.front().second;
            q.pop();
            ans=max(ans,time);
            for (auto it: adj[emp]){
                q.push({it,time+in[emp]});
            }
        }
        return ans;
    }
};