class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxfreq = 0;
        int maxsize = 0;
        
        vector<int> vec(26);

        int l = 0;
        int r = 0;
        while(r < n){
            vec[s[r] - 'A']++;
            maxfreq = max(maxfreq , vec[s[r] - 'A']);

            while((r - l + 1) - maxfreq > k){
                vec[s[l] - 'A']--;

                for(int i = 0; i < vec.size(); i++){
                    maxfreq = max(maxfreq , vec[i]);
                }
                l++;
            }

            if((r - l + 1) - maxfreq <= k){
                maxsize = max(maxsize , r - l + 1);
            }

            r++;
        }


        return maxsize;

        
    }
};