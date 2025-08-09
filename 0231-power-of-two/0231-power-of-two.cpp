class Solution {
public:

    bool isPowerOfTwo(int n) {

        if(n == -2147483648) return false;

        
        int count = __builtin_popcount(n);
        return count == 1;
    }
};