class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;

        for (string str : strs) {
            int len = str.size();
            encoded += to_string(len) + '#' + str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;

        int i{0};
        while (i < s.size()) {
            int start{i};
            while (s[i] != '#') {
                i++;
            }
            string lenStr = s.substr(start, i - start);
            int len = stoi(lenStr);
            start = ++i;
            string str = s.substr(start, len);
            decoded.push_back(str);
            i += len;
        }

        return decoded;
    }
};
