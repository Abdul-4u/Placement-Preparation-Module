class Solution {
public:
// Again Level by level
    void findCombSum(int ind, vector<int> nums, int target, vector<int> &ds, vector<vector<int>> &res){
        if(target==0){
            res.push_back(ds);
            return;
        }
        for(int i=ind; i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]){
                continue;
            }
            if(nums[i]>target)   break;
            //pick
            ds.push_back(nums[i]);
            target-=nums[i];
            findCombSum(i+1,nums,target,ds,res);
            ds.pop_back();
            target+=nums[i];
            // 
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> ds;
        findCombSum(0,candidates,target,ds,res);
        return res;
    }
};