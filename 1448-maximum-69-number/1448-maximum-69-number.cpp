class Solution {
public:
    int maximum69Number (int num) {
        vector<int> number;

        while(num > 0){
            int temp = num % 10;
            number.push_back(temp);
            num /= 10;
        }
        reverse(number.begin() , number.end());

        for(int i = 0; i < number.size(); i++){
            if(number[i] == 6){
                number[i] = 9;
                break;
            }
        }

        int ans = 0;

        for(auto digit : number){
            ans = ans * 10 + digit;
        }

        return ans;
    }
};