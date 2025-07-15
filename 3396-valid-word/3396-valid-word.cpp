class Solution {
public:
    bool isValid(string word) {
        int consonant=0;
        int vowel=0;
        string st="AEIOUaeiou";
        if(word.length()<3) return false;
        for(auto it: word){
            if(!isalpha(it) && !isdigit(it)) return false;
            if(isdigit(it)) continue;
            if(st.find(it)!=string::npos){
                vowel++;
            }
            else{
                consonant++;
            }           
        }
        if(vowel>0 && consonant>0) return true;

        return false;
    }
};