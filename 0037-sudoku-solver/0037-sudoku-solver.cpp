class Solution {
public:
bool issafe(int row, int col, char value,vector<vector<char>>& board)
{
    int n=board.size();
    for(int i=0;i<n;i++)
    {
        if(board[row][i]==value)return false;
        if(board[i][col]==value) return false;
        if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)] == value) return false;
    }
    return true;
}
bool solve(vector<vector<char>>& board)
{
    int n=board.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j]=='.')
            {
             for(char value='1';value<='9';value++)
            {
               if(issafe(i,j,value,board))
               {
                   board[i][j]=value; 
                   bool aagekasol=solve(board);
                   if(aagekasol==true) return true;
                   else board[i][j]='.';
                   
               }
            }
            return false;
            }
            
        }
    }
    return true;
}
    void solveSudoku(vector<vector<char>>& board) {
        solve (board);
    }
};