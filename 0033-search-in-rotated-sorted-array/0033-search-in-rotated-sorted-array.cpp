class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n=nums.size();
        int s=0;
        int e=n-1;
        int mid=s+(e-s)/2;
        while(s<=e){
if(target==nums[mid]){
    
    return mid;
}
            if(nums[mid] >=nums[s]){
                if(target>=nums[s] && target<=nums[mid]){
                    e=mid-1;
                }
                else{
s=mid+1;
                }
            }
            else{
                if(target>=nums[mid] && target<=nums[e]){
s=mid+1;
                }
                else{
                    e=mid-1;
                }
}
        mid=s+(e-s)/2;
            
        }
        return -1;
        
        
        
  
     
    }
};