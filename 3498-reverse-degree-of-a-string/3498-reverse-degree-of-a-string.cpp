class Solution {
public:
    int reverseDegree(string s) {
      int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            int reversedPos = 26 - (c - 'a'); 
            int stringPos = i + 1; 
            sum += reversedPos * stringPos;
        }
        return sum;  
    }
};