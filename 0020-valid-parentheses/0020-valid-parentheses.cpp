class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        map<char,char> bracket_map={
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        for( char c: s){
            if(c=='(' || c=='{' || c== '['){
                st.push(c);
            }
            else if(c==')' || c=='}' || c== ']'){
                if(st.empty()){
                    return false;
                }
                char top= st.top();
                st.pop();
                if(bracket_map[c]!=top){
                    return false;
                }
            }
        }
        return st.empty();
    }
};