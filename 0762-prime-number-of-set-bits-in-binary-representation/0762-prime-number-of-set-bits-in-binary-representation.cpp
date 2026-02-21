class Solution {
public:


    bool isPrime(int num){

        if(num <= 1){
            return false;
        }

        if(num == 2){
            return true;
        }
        if(num % 2 == 0){
            return false;
        }

        for(int i = 3; i * i <= num; i+=2){
            if(num % i == 0){
                return false;
            }
        }

        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int count = 0;

        for(int i = left; i <= right; i++){
            int num = __builtin_popcount(i);
            if(isPrime(num)){
                count++;
            }
        }

        return count;
    }
};