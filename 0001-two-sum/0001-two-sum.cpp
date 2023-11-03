class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
//         //using hash table;
//         vector<int >ans;
//         unordered_map<int ,int>mp;
//         for(int i=0;i<nums.size();i++){
// if(mp.find(target-nums[i])!=mp.end()){ //if exist then not point to end of table
//     ans.push_back(mp[target-nums[i]]);
//     ans.push_back(i);
//     return ans;
// }
// mp[nums[i]]=i;
//         }
//         return ans;
        
        // SOlution 2
        
        vector<int>result;
        for(auto it=nums.begin();it!=nums.end();++it){

            auto it2=find(it+1,nums.end(),target-*it);
            if(it2!=nums.end()){
                result.push_back(it-nums.begin());
                result.push_back(it2-nums.begin());
                break;
            }
        }
        return result;
        
        // SOLUTION 3
//         vector<int>v;
//         int i=0;
  
//         for(int i=0;i<nums.size();i++){
       
//         for(int j=i+1;j<nums.size();j++){
//             if(nums[j]==target-nums[i]){
//                 v.push_back(i);
//                 v.push_back(j);
//             }
         
//         }
//         }
        
        
//         return v;
    }
};