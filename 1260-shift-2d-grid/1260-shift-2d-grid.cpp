class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int>help;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                help.push_back(grid[i][j]);
            }
        }
    
        k=k%(m*n);  
        int ind=(m*n)-k;
        if(ind==m*n) return grid;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid[i][j]=help[ind++];
                ind%=(m*n);
            }
        }
        return grid;
    }
};