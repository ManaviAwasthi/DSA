class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans=0;
        char target='0'+digit;

        for (int x : nums) {
            string s = to_string(x);

            for (char c : s) {
                if (c == target)
                    ans++;
            }
        }

        return ans;
    }
};