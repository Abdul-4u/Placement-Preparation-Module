class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &arr, int k)
    {

        multimap<int, int,greater<>> mp;
        queue<int> qe;
        vector<int> ans;
        int n=arr.size();

        for (int i = 0; i < k; i++)
        {
            qe.push(arr[i]);
            mp.insert({arr[i], arr[i]});
        }
        ans.push_back(mp.begin()->second);

        for (int i = k; i < n; i++)
        {
            auto it = mp.find(qe.front());
            if (it != mp.end()) {
                mp.erase(it);
            }
            qe.pop();
            qe.push(arr[i]);
            mp.insert({arr[i], arr[i]});
            ans.push_back(mp.begin()->second);
        }

        return ans;
    }
};