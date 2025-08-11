class Solution {
public:


    // bool solve(vector<int>&powers ,int index, int n, vector<int>&realpowers){
        
    // if(n < 0) return false;
    // if(n == 0) return true;
    // if (index == powers.size()) return false;

    //     //include
    //     realpowers.push_back(powers[index]);
    //     if(solve(powers, index + 1, n - powers[index] ,realpowers)){
    //         return true;
    //     }
    //     realpowers.pop_back();


    //     //exclude
    //     if (solve(powers, index + 1, n, realpowers)) {
    //         return true; 
    //     }

    // return false;

    // }
    
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        // vector<int> powers;
        // vector<int> realpowers;
        // //we have to build powers vector through pick and not pick.

        // int p = 1;
        // while (p <= n) {
        //     powers.push_back(p);
        //     p *= 2;
        // }
        // solve(powers, 0 , n , realpowers);


        vector<int> realpowers;
        int power = 1;
        while (n > 0) {
            if (n & 1) {       // if lowest bit is set
                realpowers.push_back(power);
            }
            power <<= 1;       // move to next power of two
            n >>= 1;           // shift n right
        }

        int m = realpowers.size();
        vector<int> ans;

        for(auto val : queries){
            int start = val[0];
            int end = min(val[1] , m - 1); //in range

            long long prod = 1;

            for(int i= start; i <= end; i++){
                prod = (prod * realpowers[i]) % MOD;
            }

            ans.push_back((int)prod);
        }

    return ans;  
    }
};