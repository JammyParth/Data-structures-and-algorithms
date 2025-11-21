class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int>first(26 , n);
        vector<int> last(26 , -1);

        for(int i = 0; i < n; i++){
            int ch = s[i] - 'a';
            first[ch] = min(first[ch] , i);
            last[ch] = max(last[ch]  , i);
        }

        int count = 0;
        
        for(int ch = 0; ch < 26; ch++){

            vector<bool> seen(26, false);
            if(first[ch] < last[ch]){ // there are some chars between.


                for(int i = first[ch] + 1; i < last[ch];i++){
                    int integer = s[i] - 'a';
                    seen[integer] = true;
                }


                for(int i = 0; i < 26; i++){
                    if(seen[i]){
                        count++;
                    }
                }
            } 
        }


        return count;
    }
};