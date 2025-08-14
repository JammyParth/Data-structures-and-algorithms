class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        if(n < 3) return "";

        string maxi = "";
        for(int i = 2; i < n; i++){
            if(num[i] == num[i - 1] && num[i - 1] == num[i - 2]){

                if(maxi == ""){
                   maxi = num.substr(i - 2, 3);
                }
                if(num[i] > maxi[0]){
                    maxi = num.substr(i - 2, 3);
                }
            }
        }

        return maxi;
    }
};