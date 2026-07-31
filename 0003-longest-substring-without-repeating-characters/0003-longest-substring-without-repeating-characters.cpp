class Solution {
    //Approach: Sliding window and 2 pointers

public:
    int lengthOfLongestSubstring(string s) {
        vector <int> hash(256,-1); 
        int n=s.length();
        int l=0;
        int r=0;
        int mlen=0; 

        while (r<n){ //till r reaches end of str
//If the current character s[r] was seen before, and the last seen index is within the current window (hash[s[r]] >= l), then:Move the left pointer just after the last occurrence to remove the duplicate.This ensures that all characters in the window are unique.
            if (hash[s[r]]!=-1){
                if (hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            }
            mlen=max(mlen,r-l+1); //current window size
            hash[s[r]]=r; //Record the last seen index of s[r] as r
            r++;
        }
        return mlen;
    }
};