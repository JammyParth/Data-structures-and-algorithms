class Solution {
public:
    bool isPalindrome(int x) {
        string temp = to_string(x);
        int n = temp.size();

        int i = 0;
        int j = n- 1;

        while(i < j){
            if(temp[i] != temp[j]){
                return false;
            }
            i++;
            j--;
        }


    return true;
    }
};