class Solution {
public:
    char kthCharacter(int k) {
       
       int r = __builtin_popcount(k - 1); // gives the count of 1's in k - 1th element
       return 'a' + r;
    }
};