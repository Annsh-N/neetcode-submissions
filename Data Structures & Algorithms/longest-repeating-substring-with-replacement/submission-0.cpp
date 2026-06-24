class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        unordered_map<char, int> count;
        int maxFreq = 0;

        while (r < s.size()) {
            count[s[r]]++;
            maxFreq = max(maxFreq, count[s[r]]);

            if (r - l + 1 - maxFreq > k) {
                count[s[l]]--;
                l++;
            }
            r++;
        }

        return r - l;
    }
};
