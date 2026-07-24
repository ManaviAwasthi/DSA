class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set <int> one;
        unordered_set <int> two;
        unordered_set <int> thr;
        for (int it: nums){
            one.insert(it);
        }
        for (int on: one){
            for (int it: nums){
                two.insert(on^it);
            }
        }
        for (int tw: two){
            for (int it: nums){
                thr.insert(tw^it);
            }
        }
        return thr.size();
    }
};