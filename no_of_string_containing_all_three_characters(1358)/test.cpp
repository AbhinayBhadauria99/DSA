#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int result = 0;
        vector<int> mp(3, 0); // 0 - 'a', 1 - 'b', 2 - 'c'
        int i = 0, j = 0;
        
        while (j < n) {
            mp[s[j] - 'a']++;
            
            while (mp[0] > 0 && mp[1] > 0 && mp[2] > 0) {
                result += (n - j);
                mp[s[i] - 'a']--;
                i++;
            }
            
            j++;
        }
        
        return result;
    }
};

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;
    
    Solution sol;
    int result = sol.numberOfSubstrings(s);
    
    cout << "Number of valid substrings: " << result << endl;
    return 0;
}