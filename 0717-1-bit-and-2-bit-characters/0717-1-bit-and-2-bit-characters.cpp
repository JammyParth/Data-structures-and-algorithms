class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();

        int i = 0; 
        while(i < n - 1){
            if(bits[i] == 1){
                i++;
            }

            if(i == n - 1){
                return false;
            }

            i++;
        }

        return true;
    }
};