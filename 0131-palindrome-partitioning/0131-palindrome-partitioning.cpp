class Solution {
public:
bool isPalindrome(string s)
{
    string str=s;
    reverse(str.begin(), str.end());
    if(str==s)
        return true;
    return false;
}
void helper(string s,vector<vector<string>> &ans,vector<string> temp,string str,int start)
{
    //cond to terminate 
    if(start==s.length()&&isPalindrome(str))
    {
        ans.push_back(temp);
        return;
    }
    else if(start==s.length())
    {
        return;
    }
    
    //check if palindrome
    if(isPalindrome(str))
    {
         temp.push_back(str);
         //create partition
         string stemp(1, s[start + 1]);
        helper(s,ans,temp,stemp,start+1);
        temp.pop_back();
    }
    //dont create partition
    helper(s,ans,temp,str+s[start+1],start+1);
}
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        vector<vector<string>>ans;
        string str;
        str.push_back(s[0]);
        helper(s,ans,temp,str,0);
        return ans;
    }
};