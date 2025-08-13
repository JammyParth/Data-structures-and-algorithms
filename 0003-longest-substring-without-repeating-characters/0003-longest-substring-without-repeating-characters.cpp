class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        unordered_map<char, int> mp;

        int i = 0;
        int j = 0;
        int maxsize= INT_MIN;
        for(int j = 0; j < n; j++){

            if(mp.find(s[j]) != mp.end() && i <= mp[s[j]]){
                i = mp[s[j]] + 1;
            }

            mp[s[j]] = j;

            int size = j - i + 1;

            maxsize = max(maxsize, size);
        }

    return (maxsize == INT_MIN) ? 0 : maxsize;
    }
};