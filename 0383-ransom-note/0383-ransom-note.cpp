class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;

        for(auto val : magazine){
            mp[val]++;
        }

        for(auto ch : ransomNote){
            if(mp.find(ch) == mp.end()){
                return false;
            }

            else{
                if(mp[ch] == 0){
                    return false;
                }
                mp[ch]--; 
            }
        }

    return true;
    }
};