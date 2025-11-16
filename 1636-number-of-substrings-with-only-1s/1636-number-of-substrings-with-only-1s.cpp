class Solution {
public:
    int numSub(string s) {
        //count ka factorial is the answer.
        //have to carry prevprod and currcount
        const long long MOD = pow(10 , 9) + 7;
        int n = s.size();
        long long currcount = 0;
        long long totalcount = 0;
        for(int i = 0; i < n; i++){
            char ch = s[i];

            if(ch == '1'){
                currcount++;
            }

            else{
                totalcount += ((currcount * (currcount + 1)) / 2) % MOD;
                currcount = 0;
            }
        }

        if(currcount > 0){
            totalcount += ((currcount * (currcount + 1)) / 2) % MOD; 
        }

        return totalcount % MOD;
    }
};