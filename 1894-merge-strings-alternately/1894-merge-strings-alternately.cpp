class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length(), m = word2.length(), i = 0;
        string ans;

        while(i < n || i < m){
            if(i < n) ans.push_back(word1[i]);
            if(i < m) ans.push_back(word2[i]);
            i++;
        }

        return ans;
    }
};