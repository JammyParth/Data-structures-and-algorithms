class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ssize = s.size();
        int tsize = t.size();
        int i = 0;
        int j = 0;


        while(i < ssize && j < tsize){
            if(s[i] == t[j]){
                i++;
            }
            j++;
        }

        return i == ssize;
    }
};