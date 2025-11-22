class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char , int> mp;

        for(auto val : jewels){
            mp[val]++;
        }

        int count = 0;
        int n = stones.size();
        for(int i = 0; i < n; i++){
            char ch = stones[i];


            if(mp[ch] > 0){
                count++;
            }
        }


        return count;
    }
};