#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
    
    bool isLegal(const vector<vector<int>>& board, const int& x, const int& y) const {
        int m = board.size(), n = board[0].size();
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    
    int getLives(const vector<vector<int>>& board, const int&x, const int& y) const {
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (isLegal(board, nx, ny))
                cnt += board[nx][ny] & 1;
        }
        return cnt;
    }
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int lives = getLives(board, i, j);
                if (board[i][j] == 1) {
                    if (lives == 2 || lives == 3)
                        board[i][j] |= 1 << 1;
                } else if (lives == 3) {
                    board[i][j] |= 1 << 1;
                }
            }
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                board[i][j] >>= 1;
    }
};

class Solution2 {
private:
    int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
    
    bool isLegal(const vector<vector<int>>& board, const int& x, const int& y) const {
        int m = board.size(), n = board[0].size();
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    
    int getLives(const vector<vector<int>>& board, const int&x, const int& y) const {
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (isLegal(board, nx, ny) && board[nx][ny] > 0) cnt++;
        }
        return cnt;
    }
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int flag = 1;
                if (board[i][j] == 0)
                    flag = -1;
                board[i][j] = flag * (getLives(board, i, j) + 1);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == -4 || board[i][j] == 3 || board[i][j] == 4)
                    board[i][j] = 1;
                else board[i][j] = 0;
            }
        }
    }
};