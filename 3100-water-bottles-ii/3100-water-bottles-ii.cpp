class Solution {
public:
    int maxBottlesDrunk(int full, int ex) {
        int emp=full;
        int ans=emp;
        while (emp>=ex){
            emp=emp-ex;
            emp++;
            ans++;
            ex++;
        }
        return ans;
    }
};