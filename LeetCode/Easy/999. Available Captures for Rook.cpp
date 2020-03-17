#include "tools"
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int len = board.size();
        bool flag = false;
        int cnt = 0;
        for (int x = 0; x < len; x++) {
            for (int y = 0; y < len; y++) {
                if (board[x][y] != 'R') continue;
                for (int i = x - 1; i >= 0; i--) {
                    if (board[i][y] == '.') continue;
                    if (isupper(board[i][y])) break;
                    cnt++;
                    break;
                }
                for (int i = x + 1; i < len; i++) {
                    if (board[i][y] == '.') continue;
                    if (isupper(board[i][y])) break;
                    cnt++;
                    break;
                }
                for (int j = y - 1; j >= 0; j--) {
                    if (board[x][j] == '.') continue;
                    if (isupper(board[x][j])) break;
                    cnt++;
                    break;
                }
                for (int j = y + 1; j < len; j++) {
                    if (board[x][j] == '.') continue;
                    if (isupper(board[x][j])) break;
                    cnt++;
                    break;
                }
                flag = true;
                break;
            }
            if (flag) break;
        }
        return cnt;
    }
};