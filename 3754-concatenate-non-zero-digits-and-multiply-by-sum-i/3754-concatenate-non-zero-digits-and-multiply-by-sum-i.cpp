class Solution {
public:
    long long sumAndMultiply(int num) {
        string s = to_string(num);

        long long newNum = 0;
        int sum = 0;

        for (char c : s) {
            if (c != '0') {
                int d = c - '0';
                sum += d;
                newNum = newNum * 10 + d;
            }
        }

        return newNum * sum;
    }
};