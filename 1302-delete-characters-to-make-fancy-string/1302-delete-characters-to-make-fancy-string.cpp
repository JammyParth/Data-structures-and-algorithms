class Solution {
public:
    string makeFancyString(string s) {  
        int n = s.size();
        string res = "";
        
        
        for(auto ch : s){
            int size = res.size();

            if(size >= 2 && res[size - 1] == ch && res[size - 2] == ch){
                continue;
            } 

            res += ch;
        }


        return res;
    }
};