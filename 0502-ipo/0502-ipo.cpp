class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& pr, vector<int>& cap) {
        int n=pr.size();
        vector <pair<int,int>> proj;
        for (int i=0; i<n; i++){
            proj.push_back ({cap[i],pr[i]});
        }

        sort (proj.begin(), proj.end());

        priority_queue <int> pq;
        int i=0;
        while (k--){
            while (i<n && proj[i].first <=w ){
                pq.push(proj[i].second);
                i++;
            }
            if (pq.empty()){
                return w;
            }
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};