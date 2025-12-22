class Solution {
public:
    int mirrorDistance(int n) {
        int temp = n;
        int reverse = 0;

        while(temp > 0){
            int digit = temp % 10;
            temp /= 10;
            reverse = reverse * 10 + digit;
        }

        return abs(n - reverse);
    }
};