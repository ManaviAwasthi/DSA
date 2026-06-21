class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int n=costs.size();
        int ans=0;
        for (int i=0; i<n; i++){
            coins=coins-costs[i];
            if (coins>=0) ans++;
            else if (coins <0) break;
        }
        return ans;
    }
};