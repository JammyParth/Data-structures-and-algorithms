class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);
        string word;

        int count = 0;
        bool broken = true;
        while(ss >> word){

            for(int i = 0; i < brokenLetters.size(); i++){
                if(word.find(brokenLetters[i]) != string::npos){
                    broken = false;
                }
            }

            if(broken){
                count++;
            }

            broken = true;

            
        }

        return count;
    }
};