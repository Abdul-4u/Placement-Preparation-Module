class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool>hash(nums.size(),false);
    for(int i=0;i<nums.size();i++)
        {
        if(hash[nums[i]]){return nums[i];}
        hash[nums[i]]=true;
        
        }
        
        return 1;
    }
};