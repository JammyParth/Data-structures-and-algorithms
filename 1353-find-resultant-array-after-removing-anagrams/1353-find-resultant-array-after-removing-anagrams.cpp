class Solution {
public:

    bool isValid(unordered_map<char , int> &prevmp, string& curr){
        

        unordered_map<char , int> mp2;

        for(auto val : curr){
            mp2[val]++;
        }

        return prevmp == mp2;

    }
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();

        unordered_map<char , int> prevmp;

        for(auto val : words[0]){
            prevmp[val]++;
        }

        vector<string> result;
        result.push_back(words[0]);
        for(int i = 1; i < n; i++){
            if(!isValid(prevmp , words[i])){
                result.push_back(words[i]);


                prevmp.clear();
                for(auto val : words[i]){
                prevmp[val]++;
                }
            }
        }

        return result;
    }
};