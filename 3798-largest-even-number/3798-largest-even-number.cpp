class Solution {
public:
    string largestEven(string s) {
        int n = s.size();
        while(!s.empty() && s[n - 1] != '2'){
            s.erase(n - 1);
            n = s.size();
        }


        return s;
    }
};