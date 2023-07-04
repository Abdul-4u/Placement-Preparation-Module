class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int a = matrix.size();
        int b = matrix[0].size();
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        int d = 0;
        int e = b-1;
        while(d<e)
        {
            for(int i=0;i<=a-1;i++)
            {
                swap(matrix[i][d],matrix[i][e]);
            }
            d++;
            e--;
        }

        
    }
};