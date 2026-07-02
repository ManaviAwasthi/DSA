class Solution {
public:
    string reverseWords(string s) {
        reverse (s.begin(),s.end()); //reverse entire string
        int n=s.size();
        int l=0; //left
        int r=0; //right
        int i=0; //to iterate over entire string
        while (i<n){
            while (i<n && s[i]==' '){ //ignore leading spaces
                i++;
            }
            if (i==n) break;
            while (i<n && s[i]!=' '){ //to get the word, keep r at the end of the word
                s[r++]=s[i++]; //as you keep iterating
            }
            reverse(s.begin()+l, s.begin()+r); //reverse only the word
            s[r++]=' '; //add space after 
            l=r; //come to next word
            i++; //iterate as if space ws there i didnt move
        }
        s.resize(r-1);
        return s;
    }
};