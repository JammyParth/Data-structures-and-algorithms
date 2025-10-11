class Solution {
public:
    typedef long long ll;
    int n;
    unordered_map<ll , ll> mp;

    vector<ll> dp;

    ll solve(vector<ll> &power, int i){

        if(i >= n){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        //skip
        ll skip = solve(power , i + 1);


        //take
        int j = lower_bound(power.begin() + i + 1 , power.end() , power[i] + 3) - power.begin();
        ll take = (power[i] * mp[power[i]]) + solve(power , j);


        return dp[i] =  max(skip , take);

    }
    long long maximumTotalDamage(vector<int>& nums) {

        for(auto &val : nums){
            mp[val]++;
        }

        vector<ll> power;

        for(auto &val : mp){
            power.push_back(val.first);
        }

        n = power.size();

        sort(power.begin() , power.end());
        dp.assign(n + 1 , -1);

        return solve(power ,  0);
    }
};