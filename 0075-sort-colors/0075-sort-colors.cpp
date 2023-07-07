class Solution {
public:
    void sortColors(vector<int>& nums) {
        int nextZeros = 0, nextOnes = 0, nextTwos = 0;
        for(auto it : nums){
            if(it == 0) nextZeros++;
            else if(it == 1) nextOnes++;
            else nextTwos++;
        }
        int k = 0;
        for(int i=0; i<nextZeros; i++) nums[k++] = 0;
        for(int i=0; i<nextOnes; i++) nums[k++] = 1;
        for(int i=0; i<nextTwos; i++) nums[k++] = 2;
    }
};
