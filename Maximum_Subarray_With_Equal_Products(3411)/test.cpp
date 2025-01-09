#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;  
        int prefLength = pref.length();  
        for (auto word : words) {
            if (word.substr(0, prefLength) == pref) {
                count++; 
            }
        }
        return count;  
    }
};

int main() {
    vector<string> words;  // Vector to store words
    string pref;  // Prefix to search for
    
    int n;  // Number of words
    cout << "Enter the number of words: ";
    cin >> n;
    
    cout << "Enter the words:\n";
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }    
    cout << "Enter the prefix: ";
    cin >> pref;
    

    Solution solution;
    int result = solution.prefixCount(words, pref);
    cout << "Output: " << result << endl;
    
    return 0;
}
