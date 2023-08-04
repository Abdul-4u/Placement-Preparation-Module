class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        // dp[i][j] = is s[i..j] a pal(0,1);

        for(int i = 0; i < s.size(); i++)
        {
            dp[i][i] = true;
        }

        for(int i = s.size()-1; i >= 0; i--)
        {
            for(int j = i+1; j < s.size(); j++)
            {
                if(s[i] == s[j])
                {
                    if(j == i+1 || dp[i+1][j-1])
                    {
                        dp[i][j] = true;
                    }
                }
            }
        }

        int mx = 0;
        int st = -1;
        
        for(int i = 0; i < s.size(); i++)
        {
            for(int j = i; j < s.size(); j++)
            {
                if(dp[i][j])
                {
                    if(j-i+1 > mx)
                    {
                        st = i;
                        mx = j-i+1;
                    }
                }
            }
        }

        return s.substr(st,mx);
    }
};