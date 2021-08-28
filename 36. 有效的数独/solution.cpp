#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 使用 hash 表保存出现过的数字，二维到 10 是为了存储 9
        int row[9][10] = { 0 };
        int col[9][10] = { 0 };
        int box[9][10] = { 0 };

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }

                int num = board[i][j] - '0';
                if (row[i][num]) return false;
                if (col[j][num]) return false;
                if (box[j/3 + (i/3)*3][num]) return false;

                row[i][num] = 1;
                col[j][num] = 1;
                box[j/3 + (i/3)*3][num] = 1;            
            }
        }

        return true;
    }
};