class Solution {
public:

    bool reorderedPowerOf2(int n) {
        //so we are given a number. we can reorder to check if it's a power of 2.
        //it cant have leading zero.
        //i know that a number is a power of 2 if it has only 1 bit on and else off,
        //for eg 10 can be converted into 01, but leading zeros are not allowed so false.
        //lets take example 240 = 240 , 420 check for each? return true if possible else false.
        //we can run next_permutation except leading zeros.
        //check for builtin_popcount if it's 1, then return true.

        vector<string> powerStrings;

        for (long long i = 1; i <= 1000000000; i <<= 1) {
            string temp = to_string(i);
            sort(temp.begin(), temp.end());
            powerStrings.push_back(temp);
        }

        string number = to_string(n);
        sort(number.begin(), number.end());

        for (auto &val : powerStrings) {
            if (number == val) {
                return true;
            }
        }
        return false;
    }
};