class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        vector <int> ans;
        int n= v.size();
        int l=0; 
        int r=n-1;
        while(l<r){
            if (v[l]+v[r]==target) {
                ans.push_back(l+1);
                ans.push_back(r+1);
                return ans;
            }
            else if (v[l]+v[r]>target){
                r--;
            }
            else l++;
        } 
        return ans;
    }
};