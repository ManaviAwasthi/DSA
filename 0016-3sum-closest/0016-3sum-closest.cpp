class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort (nums.begin(),nums.end());
        int ans=INT_MAX;
        int diff=INT_MAX;
        for (int i=0; i<n; i++){
            int j=i+1;
            int k=n-1;
            while (j<k){
                int sum=nums[i]+nums[j]+nums[k];
                int currdiff= abs(sum-target);
                if (currdiff<diff){
                    ans=sum;
                    diff=currdiff;
                }
                if (sum == target)
                    return target;
                else if (sum < target) j++;
                else k--;
            }
        }
        return ans;
    }
};