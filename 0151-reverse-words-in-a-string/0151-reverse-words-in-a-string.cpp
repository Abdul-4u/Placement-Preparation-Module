class Solution {
public:
    string reverseWords(string s) {
        s+=" ";
        string ex="";
        string temp = "";
        for(int i = 0; i<s.length(); i++){
            if(s[i]==' ' && temp=="") continue;
            else if(temp!="" && s[i]==' '){
                if (!ex.empty()) ex = " " + ex; 
                ex = temp + ex;
                temp = "";
            }
            else{
                temp+=s[i];
            }
        }
        return ex;
    }
};
