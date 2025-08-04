class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> used(n , false);

        int count = 0;
        for(int i=0; i < n; i++){
            int placed = false;


            for(int j = 0; j < n; j++){
                if(baskets[j] >= fruits[i] && !used[j]){
                    used[j] = true;
                    placed = true;
                    break;
                }
            }

            if(!placed){
                count++;
            }
        }
    return count;
    }
};