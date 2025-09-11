class Solution {
public:


    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }

    string sortVowels(string s) {
        //store consonants and their indexes somewhere = in map.

        //store all upper and lower case vowels in a vector , sort them.

        //append them in string along with consonants.

        vector<char> vowels;
        int n = s.size();
        for(int i = 0; i < n; i++){
            char ch = s[i];

            if(isVowel(ch)){
                vowels.push_back(ch);
            }
        }

        sort(vowels.begin() , vowels.end());

        int index = 0;
        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(isVowel(ch)){
                s[i] = vowels[index++];
            }
        }


        return s;

    
    }
};