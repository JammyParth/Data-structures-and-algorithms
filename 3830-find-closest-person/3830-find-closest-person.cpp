class Solution {
public:
    int findClosest(int x, int y, int z) {
        
        int diffxz = abs(z - x);
        int diffyz = abs(z - y);

        int ans = 0;

        if(diffxz > diffyz){
           ans = 2;
        }

        else if(diffxz < diffyz){
            ans = 1;
        }

        return ans;
    }
};