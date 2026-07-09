class DSU{
public:
    vector<int>parents,rank;
    DSU(int n){
        parents.resize(n+1);
        rank.resize(n+1);
        for(int i=0;i<=n;i++){
            parents[i]=i;
        }
    }
    int findUpar(int a){
        if(a==parents[a])return a;
        return parents[a]=findUpar(parents[a]);
    }
    void join(int u,int v){
        int ult_u=findUpar(u);
        int ult_v=findUpar(v);

        if(ult_u==ult_v)return;
        if(rank[ult_u]>rank[ult_v]){
            parents[ult_v]=ult_u;
        }
        else if(rank[ult_v]>rank[ult_u]){
            parents[ult_u]=ult_v;
        }
        else {
            parents[ult_u]=ult_v;
            rank[ult_v]++;
        }

        




    }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DSU ds(n+1);
        for(int i=0;i<n;i++){
            if(i!=0){
                if((nums[i]-nums[i-1])<=maxDiff){
                    ds.join(i,i-1);
                }
            }
            if(i!=n-1){
                if((nums[i+1]-nums[i])<=maxDiff){
                    ds.join(i+1,i);
                }
            }
            
        }
        vector<bool> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            int a=queries[i][0];
            int b=queries[i][1];
            
            if(a==b)ans[i]=true;
            else{
                if(ds.findUpar(a)==ds.findUpar(b))ans[i]=true;
            }
        }
        return ans;


    }
};