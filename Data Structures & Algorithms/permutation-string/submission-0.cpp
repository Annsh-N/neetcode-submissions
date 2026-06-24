class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = 0;
        int r = 0;
        int matches = 0;
        vector<int> count(26, 0);

        for (char c : s1) {
            count[c - 'a']++;
        }

        while (r < s2.size()) {
            if (count[s2[r] - 'a']-- > 0) {
                matches++;
            }

            if (r - l + 1 > s1.size()) {
                if (count[s2[l] - 'a']++ >= 0) {
                    matches--;
                }
                l++;
            }

            if (matches == s1.size()) {
                return true;
            }

            r++;
        }

        return false;
    }
};
