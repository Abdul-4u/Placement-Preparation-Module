class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size() + 1;
        int sum=0;
    int  t = (n * (n-1))/2;
        
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
        }
          
        int x=t-sum;
        return x;
    }
};