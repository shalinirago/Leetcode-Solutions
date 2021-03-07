class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        for (int i = 1; i < grid.size()-1; i++)
        {
            for (int j = 1; j < grid[0].size()-1; j++)
            {
                if (grid[i][j] == 0)
                    if (DFS(grid, i , j))
                        count++;
            }
        }
        
        return count;
    }
    
    bool DFS(vector<vector<int>>& grid, int i, int j) {
        if (grid[i][j] == 1 || grid[i][j] == -1)
            return true;        
        
        if (i == 0 || j == 0 || i == grid.size()-1 || j == grid[i].size()-1)
            return false;
        
        grid[i][j] = -1;
        bool k = DFS(grid, i-1, j);
        bool l = DFS(grid, i+1, j);
        bool m = DFS(grid, i, j-1);
        bool n = DFS(grid, i, j+1);
        
        return k && l && m && n;
        
    }
        
};