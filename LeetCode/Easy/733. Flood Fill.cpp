#include "tools"
class Solution {
private:
    void floodFill(vector<vector<int>>& image, const int& oldColor, int sr, int sc, int newColor) {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()) return;
        if (image[sr][sc] != oldColor) return;
        image[sr][sc] = newColor;
        floodFill(image, oldColor, sr - 1, sc, newColor);
        floodFill(image, oldColor, sr + 1, sc, newColor);
        floodFill(image, oldColor, sr, sc - 1, newColor);
        floodFill(image, oldColor, sr, sc + 1, newColor);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if (oldColor != newColor) floodFill(image, oldColor, sr, sc, newColor);
        return image;
    }
};