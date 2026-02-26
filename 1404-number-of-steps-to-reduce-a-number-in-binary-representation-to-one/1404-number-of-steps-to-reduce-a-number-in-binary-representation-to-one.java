class Solution {
    public int numSteps(String s) {
        int steps = 0;
        int carry = 0;

        int i = s.length() - 1;
        while(i > 0){

            int digit = s.charAt(i) - '0';

            if((digit + carry) % 2 == 1){
                //odd number 
                steps += 2;
                carry = 1;
            }

            else{
                steps += 1;
            }
            i--;
        }

        return steps + carry;
    }
}