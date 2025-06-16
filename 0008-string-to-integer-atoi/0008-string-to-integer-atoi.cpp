class Solution {
public:
    int myAtoi(string s) {
        string temp = "";
        bool signAdded = false;
        bool digitStarted = false;

        for (auto it : s) {
            if (isspace(it)) {
                if (digitStarted || signAdded) break; // stop if space after digits or sign
                continue; // skip leading spaces
            }

            if ((it == '-' || it == '+') && !signAdded && !digitStarted) {
                temp.push_back(it);
                signAdded = true;
            }
            else if (isdigit(it)) {
                temp.push_back(it);
                digitStarted = true;
            }
            else {
                break; // non-digit, non-sign, non-space char
            }
        }

        if (temp.empty() || temp == "-" || temp == "+") return 0;

        try {
            return stoi(temp);
        } catch (...) {
            return temp[0] == '-' ? INT_MIN : INT_MAX;
        }
    }
};
