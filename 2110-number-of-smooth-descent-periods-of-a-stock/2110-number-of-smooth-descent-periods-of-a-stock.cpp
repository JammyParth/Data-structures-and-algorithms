class Solution {
public:


    long long summation(long long n){
        return (n * (n + 1)) / 2;
    }
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long count = n;
        long long i = 1;
        long long countersize = 1;
        while(i < n){
            while(i < n && prices[i - 1] - prices[i] == 1){
                countersize++;
                i++;
            }

            if(countersize > 1) count += summation(countersize) - countersize;
            countersize = 1;

            i++;
        }

        if(countersize > 1) count += summation(countersize) - countersize;

        return count;
    }
};