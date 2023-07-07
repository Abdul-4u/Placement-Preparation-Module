class Solution {
public:
vector<vector<int>> dp;
int path(int m , int n , int r , int c)
{
    if(r==m-1 || c==n-1) return 1;//reaching the end of grid
    if(dp[r][c]!=0) return dp[r][c]; //if the ways through that index is stored
   
    int d = path(m, n, r+1, c); //number of paths if we go down
    int ri = path(m, n, r, c+1);//number of paths if we go right
    dp[r][c] = ri+d;
    return dp[r][c];
}
    int uniquePaths(int m, int n) {
        dp = vector<vector<int>>(m , vector<int>(n , 0));
        return path(m, n, 0, 0);
    }
};