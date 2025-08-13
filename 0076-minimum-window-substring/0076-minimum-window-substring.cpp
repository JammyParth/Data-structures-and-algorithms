class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        int Sindex = -1;
        int minlen = INT_MAX;

        int count = 0;
        int l = 0;
        int r = 0;

        vector<int> hash(256, 0);

        for(int i= 0; i< m; i++){
            hash[t[i]]++;
        }

        while(r < n){
            
            if(hash[s[r]] > 0) count++;
            //first I have to reduce the r element from the hash array
            hash[s[r]]--;

            while(count == m){
                if(r - l + 1 < minlen){
                    minlen = r - l + 1;
                    Sindex = l;
                    
                }

                //remove elements from the left
                hash[s[l]]++;
                if(hash[s[l]] > 0) count--;
                l++;
            }
            r++;
        }

        return (Sindex == -1) ? "" : s.substr(Sindex, minlen);
    }
};