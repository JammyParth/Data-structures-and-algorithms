class Solution {
public:

    bool isPowerOfTwo(int n) {

        // if(n == -2147483648) return false;


        // int count = __builtin_popcount(n);
        // return count == 1;

        if(n == 1) return true;
        if(n <= 0) return false;

        while(n>2){
            if(n % 2 == 1) return false;
            n /= 2;
        }
        return true;
    }
};