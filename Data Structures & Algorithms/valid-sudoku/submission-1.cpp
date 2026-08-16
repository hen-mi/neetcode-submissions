class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9];
        unordered_set<char> col[9];
        unordered_set<char> square[9];


        for(int i = 0; i != 9; ++i ) {

            for(int j = 0; j != 9; ++j) {

                char c = board[i][j];

                if(c == '.') continue;

                if(row[i].count(c)) return false;
                row[i].insert(c);

                if(col[j].count(c)) return false;
                col[j].insert(c);
                int box = (i / 3) * 3 + (j / 3);
                
                if(square[box].count(c)) return false;
                square[box].insert(c);
            }
        }

        return true;
    }
};
