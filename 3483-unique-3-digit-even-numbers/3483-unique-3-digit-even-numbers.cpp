class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int digitCount[10] = {0};
        for (int d : digits) {
            digitCount[d]++;
        }
        int count = 0;
        for (int i = 100; i <= 998; i += 2) {
            int ones = i % 10;
            int tens = (i / 10) % 10;
            int hundreds = i / 100;
            int requiredCount[10] = {0};
            requiredCount[ones]++;
            requiredCount[tens]++;
            requiredCount[hundreds]++;
            
            bool canForm = true;
            for (int j = 0; j < 10; j++) {
                if (requiredCount[j] > digitCount[j]) {
                    canForm = false;
                    break;
                }
            }
            if (canForm) {
                count++;
            }
        }
        
        return count;
    }
};