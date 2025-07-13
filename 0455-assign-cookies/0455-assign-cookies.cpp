class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int si = s.size();
        int gi = g.size();
        int l = 0;
        int r = 0;
        int count = 0;

        while(l < gi && r < si){

            if(g[l] <= s[r]){
                l++;
                r++;
                count++;
            }

            else if(g[l] > s[r]){
                r++;
            }
        }


    return count; 
    }
};