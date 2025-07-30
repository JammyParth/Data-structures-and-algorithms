class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()){
           return false;
        }

        unordered_map<char, int> smap;
        unordered_map<char, int> tmap;

        for(auto &val : s){
            smap[val]++;
        }

        for(auto &val : t){
            tmap[val]++;
        }
        
        return smap == tmap;
    }
};