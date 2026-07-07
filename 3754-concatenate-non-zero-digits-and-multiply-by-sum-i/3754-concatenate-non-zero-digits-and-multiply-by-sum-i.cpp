class Solution {
public:
    long long sumAndMultiply(int nm) {
        int sum=0;
        string s=to_string(nm);
        int n=s.length();
        if (n==0) return sum;
        vector <int> nums;
        for (int i=0; i<n; i++){
            if (s[i]!='0'){
                nums.push_back(s[i]-'0');
                sum+=(s[i]-'0');
            }
        }
        int m=nums.size();
        string res;
        if (m!=0) {
            res="";
            for (int i=0; i<m; i++){
            char c= nums[i]+'0';
            res+=c;
         }
        }
        else res="0";

        long long num = stoll(res);
        long long result= num*sum;
        return result;
    }
};