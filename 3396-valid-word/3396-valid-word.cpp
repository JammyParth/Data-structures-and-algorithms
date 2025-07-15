class Solution {
public:
    bool isValid(string word) {

        int n = word.size();

        int countvowels = 0;
        int countcons = 0;
        int countnumbers = 0;
        set<char>vowels = {'a' , 'e' , 'i' , 'o' , 'u' , 'A' , 'E' , 'I' , 'O' , 'U'};
        set<char> numbers = {'0' , '1' , '2' , '3', '4' , '5' , '6' , '7' , '8' , '9'};
        if(n >= 3){
            for(int i = 0; i < n; i++){
                char ch = word[i];

                if(ch == '@' || ch == '#' || ch == '$'){
                    return false;
                }

                else if(vowels.find(ch) != vowels.end()){
                    countvowels++;
                }

                else if(numbers.find(ch) != numbers.end()){
                    countnumbers++;
                }

                else{
                    countcons++;
                }
            }
        }

        if(countvowels > 0 && countcons > 0) return true;

        else return false;
    }
};