class Solution {
public:
    long long maximumHappinessSum(vector<int>& v, int k) {
        priority_queue <long long> pq;
        int n=v.size();
        for (int i=0; i<n; i++){
            pq.push(v[i]);
        }
        int i=0;
        long long ans=0;
        while (!pq.empty() && i<k){
            int num=pq.top()-i;
            pq.pop();
            if (num>0) ans+=num;
            else break;
            i++;
        }
        return ans;
    }
};