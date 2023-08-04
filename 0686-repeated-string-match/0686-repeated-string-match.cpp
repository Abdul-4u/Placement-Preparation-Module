class Solution {
public:
   void computelps(vector<int>&lps,string s,int m)
   {
       int len=0,i=1;
       while(i<m)
       {
           if(s[i]==s[len])
           {
               len++;
               lps[i]=len;
               i++;
           }
           else
           {
               if(len!=0) len=lps[len-1];
               else{ lps[i]=0; i++;}
           }
       }
   }
    bool kmp(string a,string b,vector<int>&lps,int n,int m)
    {
        int i=0,j=0;
        while(i<n&&j<m)
        {
            if(a[i]==b[j])
            {
                i++;
                j++;
            }
            else
            {
                if(j!=0) j=lps[j-1];
                else i++;
            }
            if(j==m) break;
        }
        if(j==m) return true;
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        if(a==b) return 1;
       int n=a.size();
       int m=b.size();
       int ans=1;
       string temp=a;
       int t=n;
       while(n<m)
       {
           a+=temp;
           n+=t;
           ans++;
       }
        vector<int>lps(m,0);
        computelps(lps,b,m);
        if(kmp(a,b,lps,n,m)) return ans;
        else if(kmp(a+temp,b,lps,n+t,m)) return ans+1;
        return -1;

    }
};