class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        
        for(int i=1; i<=9; i++){
            for(int s=1; s+i-1 <=9; s++){
                int num=0;
                for(int j=s; j<=s+i-1; j++){
                    num= num*10 + j;
                }

                if(num>=low && num<=high) {
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};