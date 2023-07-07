class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;    
        v.push_back({1});
        if ( numRows == 1)return v;
        v.push_back({1,1});

        // i+1 is Row number
        for(int i=2; i < numRows;i++){
            vector<int> row(i+1,1);
            for(int j=1; j < i;j++) {
               row[j] = v[i-1][j] + v[i-1][j-1];
            }
            v.push_back(row);
        }
        return v;     
    }
};