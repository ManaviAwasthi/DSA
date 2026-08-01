class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector <int> ans;
        int top=0;
        int down=n-1;
        int l=0;
        int r=m-1;
        while (top<=down && l<=r){
            for (int i=l; i<=r; i++){
                ans.push_back(mat[top][i]); //now top row left to right traversal is done, move to next row
            }
            top++;
            for (int i=top; i<=down; i++){
                ans.push_back(mat[i][r]); //now rightmost column traversal top to bottom is done so move inward
            }
            r--;
            if (top<=down){
                for (int i=r; i>=l; i--){
                    ans.push_back(mat[down][i]); //now down row right to left traversal is done, so move up
                }
                down--;
            }
            if (l<=r){
                for (int i=down; i>=top; i--){
                    ans.push_back(mat[i][l]); //now move leftmost column, then move to next
                }
                l++;
            }
        }
        return ans;
    }
};