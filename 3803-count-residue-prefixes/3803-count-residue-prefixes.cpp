class Solution {
public:
    int residuePrefixes(string s) {
        unordered_map<char , int> mp;


        int n = s.size();

        int count = 0;
        int prefixsize = 0;
        for(int i = 0; i < n; i++){
            char ch = s[i];
            mp[ch]++;
            if((i + 1) % 3 == mp.size()){
                count++;
            }

        }


        return count;
    }
};