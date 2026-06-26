class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        unordered_map<char, char> pairs{
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        };

        for (char c : s) {
            if (pairs.count(c)) {
                open.push(c);
            } else {
                if (open.empty() || pairs[open.top()] != c) {
                    return false;
                }
                open.pop();
            }
        }

        return open.empty();
    }
};
