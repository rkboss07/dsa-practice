class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& image, int color,
                             int original) {
        if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size())
            return ;
        if (image[r][c] != original)
            return ;
    
        image[r][c] = color;
        
        dfs(r + 1, c, image, color,  original);
        dfs(r, c + 1, image, color,  original);
        dfs(r - 1, c, image, color,  original);
        dfs(r, c - 1, image, color,  original);

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int original = image[sr][sc];
        if (original == color)
            return image;
        
        dfs(sr, sc, image, color,  original);
        return image;
    }
};