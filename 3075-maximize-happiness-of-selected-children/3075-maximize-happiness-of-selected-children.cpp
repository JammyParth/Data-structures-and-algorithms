class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin() , happiness.rend());
        int n= happiness.size();
        int counter = 0;
        long long happy = 0;
        
        if(k > n){
            k = n;
        }

        for(int i = 0; i < k; i++){
            happiness[i] -= counter;
            if(happiness[i] < 0) continue;
            happy += happiness[i];
            counter++;
        }

        return happy;
    }
};