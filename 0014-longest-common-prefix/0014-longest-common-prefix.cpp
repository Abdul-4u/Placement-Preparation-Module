class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        string ans="";
        sort(str.begin(),str.end());
        int n=str.size();
        
        string s1=str[0];
        string s2=str[n-1];
        
        int i=0;
        int j=0;

        while(i<s1.size() && j<s2.size()){
            if(s1[i]!=s2[j]){
               break;
            }else{
               ans+=s1[i];
               i++;
               j++;
            }
           
        }
        return ans;
    }
};