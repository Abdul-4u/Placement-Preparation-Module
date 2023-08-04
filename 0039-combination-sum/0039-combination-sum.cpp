class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>>ans;
         vector<int> v;
         func(target,0,candidates,ans,v);
         return ans;
    }
    void func(int target, int index, vector<int>& can,  vector<vector<int>>& ans, vector<int> v )
    {   //all of the base cases
        if(target==0) //if target is zero 
        {
            ans.push_back(v);
            return;
        }
        if(target<0) //if target<0 then we return
        {
            return;
        }
        if(index==can.size())//if the size is equal to index we would return 
        {
            return;
        }
        v.push_back(can[index]);
        func(target-can[index],index,can,ans,v); //taking 
        v.pop_back();
        func(target,index+1,can,ans,v);//not taking 
    }
};