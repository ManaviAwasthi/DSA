class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int count=0;
        vector <int> v(3,-1); //v[0] stores latest index of 'a', v[1] for 'b', v[2] for 'c'
        for (int i=0; i<n; i++){
            v[s[i]-'a'] =i; //Updates the index of character seen
            if (v[0]!=-1 && v[1]!=-1 && v[2]!=-1){  // Check if we have seen all three characters at least once
                count+=1+min(v[0],min(v[1],v[2])); //all substring starting from index 0 up to min(v[0], v[1], v[2]) and ending at i is valid.
            }
        }
        return count;
    }
};