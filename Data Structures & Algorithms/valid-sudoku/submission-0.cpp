class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int numRows = board.size();
        int numCols = board[0].size();

        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                char c = board[i][j];
                if (c == '.') {
                    continue;
                }
                if (rows[i].count(c)) {
                    return false;
                }
                if (cols[j].count(c)) {
                    return false;
                }
                int box_ind = 3*(i/3) + j/3;
                if (boxes[box_ind].count(c)) {
                    return false;
                }
                rows[i].insert(c);
                cols[j].insert(c);
                boxes[box_ind].insert(c);
            }
        }
        return true;
    }
};
