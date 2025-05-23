class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> freqs;
        for(char& c : s) {
            freqs[c]++;
        }
        // Unordered set to keep track of characters in the current partition
        unordered_set<char> sc;
        // Solution array to store partition sizes
        vector<int> sol;
        // Index of the last partition boundary
        int lastIdx = -1;

        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            // Insert character into the set
            sc.insert(c);
            freqs[c]--;

            // Remove character from set if all its occurrences are included
            if(freqs[c] == 0) {
                sc.erase(c);
            }

            // If the set is empty, mark the end of a partition
            if(sc.empty()) {
                sol.push_back(i - lastIdx);
                lastIdx = i;
            }
        }
        return sol;
    }
};