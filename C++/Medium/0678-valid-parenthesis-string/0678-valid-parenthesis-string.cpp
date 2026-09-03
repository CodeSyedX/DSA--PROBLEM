class Solution {
public:
    bool checkValidString(string s) {
        int min_open = 0;
        int max_open = 0;

        for (char c : s) {
            if (c == '(') {
                min_open++;
                max_open++;
            } else if (c == ')') {
                min_open--;
                max_open--;
            } else { // '*'
                min_open--; // treat as ')'
                max_open++; // treat as '('
            }

            if (max_open < 0) return false; // More ')' than '(' and '*' combined
            if (min_open < 0) min_open = 0;  // min_open cannot drop below 0
        }

        return min_open == 0;
    }
};