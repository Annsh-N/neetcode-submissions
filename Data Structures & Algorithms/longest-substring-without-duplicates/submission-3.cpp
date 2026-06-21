class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen;
        int maxLength = 0;
        int start = 0;

        for (int i = 0; i < s.size(); i++) {

            char c = s[i];
            if (seen.count(c) && seen[c] >= start) {
                start = seen[c] + 1;
            }
            maxLength = max(maxLength, i - start + 1);
            seen[c] = i;
        }

        return maxLength;
    }
};
