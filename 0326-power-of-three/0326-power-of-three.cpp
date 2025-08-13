class Solution {
public:
    bool isPowerOfThree(int n) {
        //3 = 11
        //9 = 1001
        //27 = 11011
        //81 = 1010001
        //either bit shifting
        if(n < 1) return false;
        //or else using while
        while(n % 3 == 0){
            n /= 3;
        }


        return n == 1;

    }
};