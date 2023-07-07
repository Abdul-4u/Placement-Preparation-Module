class Solution {
public:
   void nextPermutation(vector<int>& nums)
    {
        int n = nums.size();
        int index1,index2;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                index1 = i;
                break;
            }
        }
        if(index1<0)
        {
            reverse(nums.begin(),nums.end());
        }
        else
        {
            for(int i=n-1;i>=index1;i--)
            {
                if(nums[i]>nums[index1])
                {
                    index2 = i;
                    break;
                }
            }
            swap(nums[index1],nums[index2]);
            reverse(nums.begin()+index1+1,nums.end());    
        }
        
    }
};