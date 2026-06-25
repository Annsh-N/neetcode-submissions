class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;

        for (char c : t) {
            need[c]++;
        }

        int required = need.size();
        int have = 0;

        int l = 0;
        int start = 0;
        int bestLen = INT_MAX;

        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;

            if (need.count(c) && need[c] == window[c]) {
                have++;
            }

            while (have == required) {
                if (r - l + 1 < bestLen) {
                    bestLen = r - l + 1;
                    start = l;
                }

                char leftChar = s[l];
                window[leftChar]--;

                if (need.count(leftChar) && window[leftChar] < need[leftChar]) {
                    have--;
                }

                l++;
            }
        }

        return bestLen == INT_MAX ? "" : s.substr(start, bestLen);
        
    }
};
