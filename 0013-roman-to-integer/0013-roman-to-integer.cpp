class Solution {
public:
    int romanToInt(string s) {
        int res = 0;

        for(int i = 0; i < s.size(); i++){

            if(s[i] == 'I' && i + 1 < s.size() && s[i + 1] == 'V'){
                res += 4;
                i++;
                continue;
            }

            if(s[i] == 'I' && i + 1 < s.size() && s[i + 1] == 'X'){
                res += 9;
                i++;
                continue;
            }


            if (s[i] == 'X' && i + 1 < s.size()) {
                if (s[i + 1] == 'L') {
                    res += 40;
                    i++; continue;
                }
                if (s[i + 1] == 'C') {
                    res += 90;
                    i++; continue;
                }
            }

            if (s[i] == 'C' && i + 1 < s.size()) {
                if (s[i + 1] == 'D') {
                    res += 400;
                    i++; continue;
                }
                if (s[i + 1] == 'M') {
                    res += 900;
                    i++; continue;
                }
            }
            
            if(s[i] == 'I'){
                res += 1;
            }

            if(s[i] == 'M'){
                res += 1000;
            }
            if(s[i] == 'D'){
                res += 500;
            }
            if(s[i] == 'C'){
                res += 100;
            }

            if(s[i] == 'L'){
                res += 50;
            }

            if(s[i] == 'X'){
                res += 10;
            }

            if(s[i] == 'V'){
                res += 5;
            }

        
        }

    return res;
    }
};