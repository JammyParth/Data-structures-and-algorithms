class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);

        string word;
        vector<string> words;

        while(ss >> word){
            words.push_back(word);
        }

        int n = words.size();
        string ans = words[n - 1];

        return ans.size();
    }
};