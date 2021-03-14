class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                board[i][j] = changeCellVal(board, i, j);                
            }
        }
        
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] < 0)
                {
                    board[i][j] = 0;
                }
                if (board[i][j] > 1)
                {
                    board[i][j] = 1;
                }
            }
        }
    }
    
    int changeCellVal(vector<vector<int>>& board, int i, int j){
        vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        int n_live = 0, change_val = board[i][j], x, y;
        
        for (int idx = 0; idx < dx.size(); idx++)
        {
            x = i+dx[idx];
            y = j+dy[idx];
            
            if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
                continue;
            
            if (board[x][y] == 1 || board[x][y] == -1)
                n_live++;
        }
        
        if (board[i][j] == 1)
        {
            if (n_live < 2)
            {
                change_val = -1;
            }
            if (n_live == 2 || n_live == 3)
            {
                change_val = board[i][j];
            }
            if (n_live > 3)
            {
                change_val = -1;
            }
        }
        else
        {
            if (n_live == 3)
                change_val = 2;
        }
        
        return change_val;
    }
};