class Solution {
public:

    int replace(int n){
        int sum = 0;

        while(n > 0){
            int digit = n % 10;
            sum += (digit * digit);   
            n/= 10;
        }

        return sum;
    }
    bool isHappy(int n) {
        set<int> seen;

        while(n != 1 && !seen.count(n)){
            seen.insert(n);
            n = replace(n);
        } 


        return n == 1;
    }
};