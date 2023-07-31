//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends





class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
   vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int> arr;
        bool visited[V]={false};
        arr.push(0); visited[0]=true;
        vector<int> ans;
        while (arr.size()!=0){
            int head=arr.front();
            for (int i=0; i<adj[head].size(); i++){
                int val=adj[head][i];
                if (visited[val]==false){
                    visited[val]=true;
                    arr.push(val);
                }
            }
            ans.push_back(head);
            arr.pop();
        }
        return ans;
    }


};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends