class Solution {
public:


    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }


    int maxFreqSum(string s) {
        
        unordered_map<char , int> mp;


        for(auto ch : s)
        {
            mp[ch]++;
        }

        int maxvowel = 0;
        int maxcons = 0;
        for(auto val : mp){

            if(isVowel(val.first)){
                maxvowel = max(maxvowel , val.second);
            }

            else{
                maxcons = max(maxcons , val.second);
            }
        }


        return maxvowel + maxcons;
    }
};