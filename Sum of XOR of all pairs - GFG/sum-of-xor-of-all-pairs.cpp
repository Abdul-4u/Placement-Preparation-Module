//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
      long long int sumXOR(int arr[], int n)
    {
    long long int sum=0;
        for(int j=0;j<32;j++){
            int zcount=0; 
            int ocount=0;
            for(int i=0;i<n;i++){
                if(arr[i]%2==1){
                    ocount++;
                }
                else{
                    zcount++;
                }
                arr[i]=arr[i]/2;
                
            }
            sum=sum+((pow(2,j))*zcount*ocount);
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends