class Solution {
public:

    bool isValid1(string s){
        int n= s.size();
        int i = 0;
        int j = n - 1;

        int cnt = 0;
        while(i <= j){

            if(cnt > 1){
                return false;
            }

            if(s[i] == s[j]){
                i++;
                j--;
            }

            else{
                cnt++;
                i++;
            }
        }

        return true;
    }


    bool isValid2(string s){
        int n= s.size();
        int i = 0;
        int j = n - 1;

        int cnt = 0;
        while(i <= j){

            if(cnt > 1){
                return false;
            }

            if(s[i] == s[j]){
                i++;
                j--;
            }

            else{
                cnt++;
                j--;
            }
        }

        return true;
    }
    bool validPalindrome(string s) {
        bool res1 = isValid1(s); 
        bool res2 = isValid2(s);

        return res1 || res2;
    }
};