class Solution {
public:
    bool isPalindrome(int x) {
        
        long long reversednum = 0;
        long long original = x;
        while(x > 0){
            long long temp = x % 10;
            reversednum = reversednum * 10 + temp;
            x /= 10;
        }

        return reversednum == original;
    }
};