class Solution {
public:
    int myAtoi(string s) {
        
        int i = 0; int sign = 1;
        int n = s.size();
        
        long long number = 0;

        //reducing white spaces.
        while(s[i] == ' '){
            i++;
        }

        //check if there is a sign
        if(s[i] == '-'){
            sign = -1;
            i++;
        }

        else if(s[i] == '+'){
            i++;
        }

        while(isdigit(s[i]) && i < n){
            number = number * 10 + (s[i] - '0');

            if(number * sign > INT_MAX) return INT_MAX;
            if(number * sign < INT_MIN) return INT_MIN;

            i++;

        }

        return (int)(number * sign);
    }
};