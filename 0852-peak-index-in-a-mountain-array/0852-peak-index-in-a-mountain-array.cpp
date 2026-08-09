class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int n=nums.size();
        int l=0, r=n-1;
        int mid;
        while (l<r){
            mid= l+ (r-l)/2;
            if (nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if (nums[mid-1]<=nums[mid] && nums[mid]<=nums[mid+1]){
                l=mid+1;
            }
            else {
                r=mid;
            }
        }
        return -1;
    }
};