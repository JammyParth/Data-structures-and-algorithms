class Solution {
public:

    vector<pair<int , int>> serves = {{100 , 0} , {75, 25} , {50 , 50} , {25 , 75}};
    vector<vector<double>> dp;

    double prob_a_empty(double a, double b){
        
        if(a <= 0 && b <= 0) return 0.5;
        if(a <= 0) return 1.0;
        if(b <= 0) return 0.0;

        if (dp[a][b] >= 0) return dp[a][b];

        double prob = 0.0;

        for(auto pair: serves){
            int a_taken = pair.first;
            int b_taken = pair.second;

            prob += prob_a_empty(a - a_taken ,b - b_taken);
        }

        return dp[a][b] = 0.25 * prob;
    }

    double soupServings(int n) {

        if(n >= 4800) return 1;
        dp.assign(n + 1, vector<double>(n + 1, -1.0));

        return prob_a_empty(n , n);
    }
};