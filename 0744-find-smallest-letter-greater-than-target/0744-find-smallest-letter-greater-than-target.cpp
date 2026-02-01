class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        

        int ans = 256;
        int anstemp = 256;
        for(auto ch : letters){
            if(ch > target){
                int temp = ch - target;
                if(temp < anstemp){
                    anstemp = temp;
                    ans = ch;
                }
            }
        }

        return ans == 256 ? letters[0] : ans;
    }
};