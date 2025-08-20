class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        
        int size = s.size();
        vector<string> ans;
        for(int i = 0; i < size; i+=k){

            if(i + k <= size){
                ans.push_back(s.substr(i , k));
            }
            else{
                string last = s.substr(i);
                last += string(k - last.size() , fill);
                ans.push_back(last);
            }
        }
    return ans;
    }
};