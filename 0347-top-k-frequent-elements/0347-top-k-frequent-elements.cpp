class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(auto x : nums){
            m[x]++;
        }

        // run loop k times and find max freq and then element to corresponding freq 
        while(k--){
            int freq = 0 , ele = 0;
            for(auto x : m){
                if(x.second != -1){ // if -1 means it has been added already
                    if(x.second >= freq){
                        freq = max(freq,x.second);
                        ele = x.first;
                    }
                }
            }

            ans.push_back(ele);
            // then erase that element from map , so that it dont come together
            m[ele] = -1; 
        }


        return ans;
    }
};