class Solution {
public:

    // Process

    // Ignore leading whitespaces
    // Can be Done by substring function

    // Now if (s[0] == '-' ){
    //    then ans will be negative
    // }

    // Some TestCases
    // " 4193 words " -> 4193
    // "abcxyz 72" -> 0
    // "  -4123abc" -> -4123

    bool check(char ch){
        for(int i=0 ; i<=9 ;i++){
            if(ch == '0'+i ){
                return true;
            }
        }
        return false;
    }


    int myAtoi(string s) {
        
        long long ans =0;

        if(s.length() == 0){
            return ans;
        }

        int i=0;

        while(i<s.length() && s[i]==' ' ){
            i++;
        }
        s = s.substr(i);

        int negSign = 1;

        if(s[0] == '+' && s[1] == '-'){
            return ans;
        }

        if(s[0] == '-' && s[1] == '+'){
            return ans;
        }

        if(s[0] == '+'){
            s = s.substr(1);
        }

        if(s[0] == '-'){
            s= s.substr(1);
            negSign = -1;
        }

        int j =0;

        while(j < s.length()){

            if( check(s[j]) ){
                int k = s[j]-'0';
                ans = ans*10 + k;

                if(negSign == -1 && -1*ans < INT_MIN){
                    return INT_MIN;
                }

                if(negSign == 1 && ans>INT_MAX){
                    return INT_MAX;
                }


                j++;
                continue;
            }
            if(s[j] == ' '){
                break;
            }
            if(s[j] == '+'){
                break;
            }
            if(s[j] == '-'){
                break;
            }
            break;
        }
        
        return (int)(ans*negSign);

    }
};