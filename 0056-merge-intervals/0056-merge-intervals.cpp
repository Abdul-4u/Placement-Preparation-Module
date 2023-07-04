class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& arr) {
		sort(arr.begin(),arr.end());
		vector<vector<int>> ans = {arr[0]};
		for(int i = 0 ; i < arr.size() ; i++){
			int s = arr[i][0] , e = arr[i][1];
			int as = ans[ans.size()-1][0] , ae = ans[ans.size()-1][1];
			if(as <= s and s <= ae) {
				ans[ans.size()-1][1] = max(e,ae); 
			}else{
				ans.push_back({s,e});
			}
		}
		return ans;
	}
};