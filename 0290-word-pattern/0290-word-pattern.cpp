class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);

        string word;
        unordered_map<char, string> mp;
        
        int i = 0;
        while(ss >> word){
            if (i >= pattern.size()) return false; // more words than pattern
            char ch = pattern[i];

            if(mp.count(ch)){
                if(mp[ch] != word) return false;
            }
            else {
                // check if word is already mapped to another char
                for (auto &p : mp) {
                    if (p.second == word) return false;
                }
                mp[ch] = word;
            }
            i++;
        }

    return i == pattern.size();
    }
};