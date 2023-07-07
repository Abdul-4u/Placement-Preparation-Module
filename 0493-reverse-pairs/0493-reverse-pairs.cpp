class Solution {
public:
    int merge(vector<int>& nums,int start,int md,int high){
        int ans=0;
        int j=md;
        for(int i=start;i<md;i++){
            while(j<=high && nums[i]>2LL *nums[j])
                j++;
                    ans+=(j-md);
        }
        vector<int> temp;
       int i=start;
        j=md;
        while(i<md && j<=high){
            if(nums[i]<=nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
            
        }
        while(i<md)
            temp.push_back(nums[i++]);
        while(j<=high)
            temp.push_back(nums[j++]);
        for(int z=start;z<=high;z++){
            nums[z]=temp[z-start];
        }
        return ans;
    }
    
    int mergesort(vector<int>& nums,int low, int high){
        int res=0;
        if(low>=high) return 0;
        else{
            int mid=(low+high)/2;
            res=mergesort(nums,low,mid);
            res+=mergesort(nums,mid+1,high);
            res+=merge(nums,low,mid+1,high);
        }
        return res;
        
    }
    
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergesort(nums,0,n-1);
    }
};