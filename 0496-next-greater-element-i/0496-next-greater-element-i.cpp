
class Solution {
public:
    void nextElement(unordered_map<int, int> &mp, stack<int> &s, vector<int>& nums2, int m){

        for(int i = nums2.size()-1; i>=0; i--){
            while(!s.empty()){
                if(s.top() > nums2[i]){
                    mp[nums2[i]] = s.top();
                    break;
                }
                s.pop();
            }
            if(s.empty()) mp[nums2[i]] = -1;

            s.push(nums2[i]);
        }
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> ans;
        stack<int> s;
        int m = nums2.size();
        int n = nums1.size();
        s.push(nums2[m-1]);
        
        nextElement(mp, s, nums2, m);

        for(int i = 0; i<nums1.size(); i++){
            ans.push_back(mp[nums1[i]]);
        }

        return ans;
    }
};