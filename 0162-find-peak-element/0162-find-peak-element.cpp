class Solution {
public:
    int findPeakElement(vector<int>& v) {
        int n=v.size();
        if (n==1) return 0;
        if (v[0]>v[1]) return 0;
        if (v[n-1] > v[n-2]) return n-1;

        int low=1;
        int high=n-2;
        while (low<=high){
            int mid= (low+high)/2;
            if (v[mid]>v[mid-1] && v[mid]>v[mid+1]){
                return mid;
            }
            //if the mid is on increasing curve then peak will be to right of it
            else if(v[mid]>v[mid-1]){
                low=mid+1;
            }
            //otherwise mid will be on a decreasing curve, then peak will be to left
            else {
                high=mid-1;
            }
        }

        return -1;
    }
};