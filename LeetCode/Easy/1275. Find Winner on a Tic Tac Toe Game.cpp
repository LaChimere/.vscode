#include "tools"
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int a = 0, b = 0, len = moves.size();
        vector<int> win({
            0b000000111, 0b000000111 << 3, 0b000000111 << 6, 
            0b001001001, 0b001001001 << 1, 0b001001001 << 2, 
            0b100010001, 0b001010100
        });
        for (int i = 0; i < len; i++) {
            if (i & 1) b ^= 1 << (3 * moves[i][0] + moves[i][1]);
            else a ^= 1 << (3 * moves[i][0] + moves[i][1]);
        }
        for (int i : win) {
            if ((a & i) == i) return "A";
            if ((b & i) == i) return "B";
        }
        return len == 9 ? "Draw" : "Pending";
    }
};

// class Solution {
// private:
//     vector<string> grid = vector<string>(3, "   ");
//     bool judgeRow(char c, int row) {
//         return grid[row][0] == c && grid[row][1] == c && grid[row][2] == c;
//     }
//     bool judgeCol(char c, int col) {
//         return grid[0][col] == c && grid[1][col] == c && grid[2][col] == c;
//     }
//     bool judgeDia(char c) {
//         return (grid[0][0] == c && grid[1][1] == c && grid[2][2] == c) || (grid[0][2] == c && grid[1][1] == c && grid[2][0] == c);
//     }
//     bool judgeA() {
//         for (int i = 0; i < 3; i++)
//             if (judgeRow('X', i)) return true;
//         for (int j = 0; j < 3; j++)
//             if (judgeCol('X', j)) return true;
//         return judgeDia('X');
//     }
//     bool judgeB() {
//         for (int i = 0; i < 3; i++)
//             if (judgeRow('O', i)) return true;
//         for (int j = 0; j < 3; j++)
//             if (judgeCol('O', j)) return true;
//         return judgeDia('O');
//     }
// public:
//     string tictactoe(vector<vector<int>>& moves) {
//         for (int i = 0; i < moves.size(); i++) {
//             if (i % 2 == 0) grid[moves[i][0]][moves[i][1]] = 'X';
//             else grid[moves[i][0]][moves[i][1]] = 'O';
//             if (i < 4) continue;
//             if (judgeA()) return "A";
//             if (judgeB()) return "B";
//         }
//         return moves.size() == 9 ? "Draw" : "Pending";
//     }
// };