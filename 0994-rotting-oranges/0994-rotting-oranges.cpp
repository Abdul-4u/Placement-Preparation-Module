class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int orangesRotting(vector<vector<int>>& grid) {
        deque<pair<int, int>> rotten;
        int rows = grid.size();
        int cols = grid[0].size();

        int freshNum = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 2) {
                    rotten.push_back({row, col});
                }
                if (grid[row][col] == 1) {
                    freshNum++;
                }
            }
        }

        if (freshNum == 0) return 0;
        if (rotten.empty()) return -1;

        int res = -1;
        while (!rotten.empty()) {
            int size = rotten.size();
            for (int i = 0; i < size; i++) {
                auto p = rotten.front();
                rotten.pop_front();
                int row = p.first;
                int col = p.second;
                for (auto dir : dirs) {
                    int newRow = row + dir[0], newCol = col + dir[1];
                    // if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) continue;
                    // if (grid[newRow][newCol] != 1) continue;
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 1) {
                        rotten.push_back({newRow, newCol});
                        grid[newRow][newCol] = 2;
                        freshNum--;
                    }
                }
            }
            res++;
        }

        if (freshNum == 0) {
            return res;
        }
        return -1;
    }
};