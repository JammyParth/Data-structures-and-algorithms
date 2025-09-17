class Solution {
public:

    string solve(int n , int i, string &str){

        if(i == n - 1){
            return str;
        }

        string next = "";
        char element = str[i];
        int count = 1;

        for (int x = 1; x < str.length(); x++) {
            if (str[x] == str[x - 1]) {
                count++;
            }
            else{
                next += to_string(count) + str[x - 1];
                count = 1;
            }
        }
        
        next += to_string(count) + str.back();

        return solve(n , i + 1 , next);
    
    }

    string countAndSay(int n) {
        string str = "1";
        return solve(n , 0 , str);
        
    }
};