class Solution {
public:
    int maxBottlesDrunk(int full, int ex) {
        int ans=full;
        while (full>=ex){
            full=full-ex+1;
            ans++;
            ex++;
        }
        return ans;
    }
};