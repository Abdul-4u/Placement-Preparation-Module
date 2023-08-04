class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        //Input: nums = [1,1,0,1,1,1]
        //Output: 3
        int cons=0;
        int count =0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
               { count++;
			   cons=max(cons,count);   // store the maximum count
			   }
            else
				count=0;   // whenever zero is encountered reset the count and then start counting again
        }
        return max(cons,count);
    }
};