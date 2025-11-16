class Solution {
public:
    int countHomogenous(string s) {
        int n = s.size();
        long long currcharcount = 1;
        int currchar = s[0];
        long long totalcount = 0;

        const long long MOD = pow(10 , 9) + 7;
        for(int i = 1; i < n; i++){
            char ch = s[i];

            if(ch == currchar){
                currcharcount++;
            }

            else{
                totalcount += ((currcharcount * (currcharcount + 1)) / 2) % MOD;
                currchar = ch;
                currcharcount = 1;
            }
        }

        if(currcharcount > 0){
            totalcount += ((currcharcount * (currcharcount + 1)) / 2) % MOD;

        }
    return totalcount % MOD;
    }
};