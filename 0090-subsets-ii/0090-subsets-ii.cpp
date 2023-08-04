class Solution {
public:
    void solve(vector<int>& nums,int si,vector<int>&ans,vector<vector<int>>&op){
        op.push_back(ans);
        for(int i=si; i<nums.size(); i++){
            if(i!=si && nums[i]==nums[i-1])continue;
            ans.push_back(nums[i]);
            solve(nums,i+1,ans,op);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>op;
        vector<int>ans;
        sort(nums.begin(),nums.end());
        solve(nums,0,ans,op);
        return op;
    }
};