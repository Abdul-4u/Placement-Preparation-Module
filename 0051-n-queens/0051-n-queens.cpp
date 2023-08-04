class Solution {
    vector<vector<string>> result;
    int n;
    vector<string> addQueen(vector<string> currentPosition, int row, int col) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == row || j == col || abs(j-col) == abs(i - row)) {
                    currentPosition[i][j] = '.';
                }
            }
        }
        currentPosition[row][col] = 'Q';
        return currentPosition;
    }

    void solveNQueens(int n, vector<string> currentPosition, int row) {
        if(row == n) {
            result.push_back(currentPosition);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(currentPosition[row][i] == '.') continue;
            vector<string> newPosition = addQueen(currentPosition, row, i);
            solveNQueens(n, newPosition, row+1);
        }
    }
public:
    vector<vector<string>> solveNQueens(int m) {
        n = m;
        vector<string> one(n, string(n, '#'));
        solveNQueens(n, one, 0);
        return result;
    }
};