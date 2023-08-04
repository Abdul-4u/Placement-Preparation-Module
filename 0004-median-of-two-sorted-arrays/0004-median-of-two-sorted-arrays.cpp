class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        int n = nums1.size();
        int m = nums2.size();
        for(auto i : nums1){
            v.push_back(i);
        }
        for(auto i : nums2){
            v.push_back(i);
        }
        sort(v.begin(),v.end());
        double x = 0;
        int y = v.size();
        if(v.size()%2==0){
            x = double(v[y/2-1] + v[y/2])/2;
        }
        else{
            x = v[y/2];
        }
        return x;
    }
};