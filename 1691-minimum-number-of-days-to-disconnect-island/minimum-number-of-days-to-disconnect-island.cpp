class Solution {
public:
    const vector<int> directions = {-1, 0, 1, 0, -1};
    int rows, cols;

    int minDays(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        if (countIslands(grid) != 1) {
            return 0;
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (countIslands(grid) != 1) {
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }

    int countIslands(vector<vector<int>>& grid) {
        int islandCount = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    dfs(i, j, grid);
                    ++islandCount;
                }
            }
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 2) {
                    grid[i][j] = 1;
                }
            }
        }
        return islandCount;
    }

    void dfs(int row, int col, vector<vector<int>>& grid) {
        grid[row][col] = 2;
        for (int k = 0; k < 4; ++k) {
            int newRow = row + directions[k], newCol = col + directions[k + 1];
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 1) {
                dfs(newRow, newCol, grid);
            }
        }
    }
};
