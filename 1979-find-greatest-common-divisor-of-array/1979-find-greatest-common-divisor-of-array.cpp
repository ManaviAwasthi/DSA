class Solution {
private:
    int gcd(int a,int b){
        return b==0? a:gcd(b,a%b);
    }
public:
    int findGCD(vector<int>& nums) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int n=nums.size();
        for (int i=0; i<n; i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
        return gcd(mini,maxi);
    }
};