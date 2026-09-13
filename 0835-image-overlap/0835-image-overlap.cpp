class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans=INT_MIN;
        vector<vector<int>> ones1;
        for(int i=0;i<img1.size();i++){
            for(int j=0;j<img1.size();j++){
                if(img1[i][j]==1){
                    ones1.push_back({i,j});
                }
            }
        }
       
        int n=img1.size();
        for(int row=-(n-1);row<n;row++){
            for(int col=-(n-1);col<n;col++){
                int count=0;
                for(int k=0;k<ones1.size();k++){
                    int newRow=ones1[k][0]+row;
                    int newCol=ones1[k][1]+col;
                    if(newRow>=0 && newRow<n && newCol>=0 && newCol<n){
                        if(img2[newRow][newCol]==1){
                            count ++;
                        }
                    }
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};