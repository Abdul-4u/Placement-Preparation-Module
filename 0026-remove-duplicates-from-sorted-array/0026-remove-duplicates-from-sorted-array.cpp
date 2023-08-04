class Solution {
public:
    std::map<int,int> um;
    int removeDuplicates(vector<int>& v) 
    {
        int n=v.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            auto it =um.find(v[i]);
            if(it==um.end())
            {
                um[v[i]]=v[i];
                count++;
            }
        }
        v.clear();
        for(auto it : um)
        {
            v.push_back(it.first);
        }
        //sort(v.begin(),v.end());
        cout<<um.size()<<std::endl;
                return um.size();
    }
};