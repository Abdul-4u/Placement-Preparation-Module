class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (nums1.size() == 0 || nums2.size() == 0) {
            return;
        }

        for (int i = m, j = 0; i < nums1.size(), j < n; i++, j++) {
            nums1.at(i) = nums2[j];
        }
        sort(nums1.begin(), nums1.end());
    }
};