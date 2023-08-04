class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, l = 0, r = height.size() - 1, lastMaximaIndex;

        // find approriate space where water will be actually be stored
        while(l + 1 < height.size() && height[l] < height[l + 1]) l++;
        while(r - 1 < -1 && height[r] > height[r - 1]) r--;

        // find last maxima
        lastMaximaIndex = l;
        for(int i = l + 1; i < height.size(); ++i){
            if(height[i] >= height[lastMaximaIndex]) lastMaximaIndex = i;    
        }

        // for left part of maxima
        for(int i = l + 1; i < lastMaximaIndex; ++i){
            if(height[l] <= height[i]) l = i;
            else ans += abs(height[l] - height[i]);
        }

        // for right part of maxima
        l = lastMaximaIndex;
        for(int i = r - 1; i >= l; --i){
            if(height[r] <= height[i]) r = i;
            else ans += abs(height[r] - height[i]);
        }
        
        return ans;
    }
};