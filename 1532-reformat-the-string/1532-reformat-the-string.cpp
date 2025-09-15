class Solution {
public:

    string reformat(string s) {
        
        // isalpha(c) → true if c is a letter (A–Z, a–z).
        // isdigit(c) → true if c is a digit (0–9).

        vector<char> digits;
        vector<char> alphas;

        for(int i = 0; i < s.size() ; i++){
            char ch = s[i];

            if(isdigit(ch)){
                digits.push_back(ch);
            }

            else{
                alphas.push_back(ch);
            }
        }

        int n = digits.size();
        int m = alphas.size();

        if(abs(n - m) > 1){
            return "";
        }

        string ans = "";

        int z = min(n, m);
        int temp = z;

        int i = 0;

        if(m > n){
        while(z > 0){
            ans += alphas[i];
            ans += digits[i];
            i++;
            z--;  
        }
        }

        else{
            while(z > 0){
            ans += digits[i];
            ans += alphas[i];
            i++;
            z--;  
            }
        }

        if(temp != n ) ans += digits[n - 1];
        if(temp != m ) ans += alphas[m - 1];
        

        return ans;

    }
};