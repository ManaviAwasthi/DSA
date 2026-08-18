class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map <int, vector <int>> xcoord;
        unordered_map <int, vector <int>> ycoord;
        
        //har building ki row aur column me jitni bhi buildings hain unhe add krna in vector
        for (auto &it : buildings){
            xcoord[it[0]].push_back(it[1]); 
            ycoord[it[1]].push_back(it[0]);
        }

        //ab sare sort krdo taaki smallest pata chal jaye

        for (auto &it : xcoord) {
            sort (it.second.begin(), it.second.end());
        }
        for (auto &it : ycoord) {
            sort (it.second.begin(), it.second.end());
        }

        int num=0; //number of covered buildings
        //ab har building k liye check karenge ki vo chaaro side se connected hai ki nhi
        //aisa tabhi hoga jab usse bada aur usse chhota x aur y coordinate exist nhi krega
        //so we check whether its not at any of the end of sorted vectors
        //if yes, we count it, otherwise its not covered     
        for (auto &it: buildings){
            int x= it[0];
            int y= it[1];

            auto &column = xcoord[x];   
            auto &rows = ycoord[y];   

            int n1= column.size();
            int n2= rows.size();
            
            if ((column[0]!=y && column[n1-1]!=y) && (rows[0]!=x && rows[n2-1]!=x)) num++;
        }

        return num;
    }
};