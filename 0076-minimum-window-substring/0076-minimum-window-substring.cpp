class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        int Sindex = -1;
        vector <int> hash(256 , 0);

        int l = 0;
        int r = 0;
        int minlen = INT_MAX;

        for(int i = 0; i< t.size(); i++){
            hash[t[i]]++;
        }

        int count = 0;
        while(r < n){

            if(hash[s[r]] > 0) count++;
            hash[s[r]]--; //decrease the element inside the hashmap.
            

            while(count == m){
                
                if(r - l + 1 < minlen){
                    minlen = r - l + 1;
                    Sindex = l;
                }


                hash[s[l]]++; //increase from behind.
                if(hash[s[l]] > 0) count--;
                l++;
            }

            r++;
        }

    return (Sindex == -1) ? "" : s.substr(Sindex, minlen);
    }
};