class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //storing index and pushing start to recent index if char found again.

        int n = s.size();
        int start = 0;
        int maxcount = 0;
        unordered_map<char, int> mp;


        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(mp.count(ch) && start <= mp[ch]){
                start = mp[ch] + 1;
            }
            maxcount = max(maxcount , i - start + 1);
            mp[ch] = i;  
        }


        return maxcount;
    }
};