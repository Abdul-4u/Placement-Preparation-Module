class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int>st;    
        int area = 0;
        int n = heights.size();
        for(int i = 0;i < n;i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int h = heights[st.top()];
                st.pop();
                int l = -1;
                if(st.empty()){
                    l = -1;
                }
                else{
                    l = st.top();
                }
                area = max(area,h*(i-l-1));
            }
            st.push(i);
        }
        return area;
    }
};