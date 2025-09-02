class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        // If the last character is '1', we can't reach it.
        if (s.back() == '1') {
            return false;
        }

        queue<int> q;
        q.push(0);
        
        // 'maxi' tracks the maximum index we have already "scanned" for possible jumps.
        int maxi = 0;
        while (!q.empty()) {
            int i = q.front();
            q.pop();

            // If we've reached the last index, we're done.
            if (i == s.length() - 1) {
                return true;
            }

            // Start scanning for new jumps from the greater of:
            // 1. The previous maximum scanned index + 1
            // 2. maxi+1 is to avoid redundant checks, the numbers that has already been put in queue
            int start = max(i + minJump, maxi + 1); //think about next iteration when maxi would have been updated .tab hum maxi tak to jump kar hi sakte the pechli iteration me .

            // Iterate through all possible jump destinations
            for (int j = start; j <= min(i + maxJump, (int)s.length() - 1); ++j) {
                // If we find a '0', it's a valid jump destination.
                if (s[j] == '0') {
                    q.push(j);
                }
            }

            // Update maxi to the farthest index we've just considered.
            maxi = i + maxJump;
        }

        // If the queue becomes empty and we haven't reached the end, it's unreachable.
        return false;
    }
};