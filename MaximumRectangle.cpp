class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int res = INT_MIN;
        if(n==0)
            return 0;
        stack<int> s;
        for(int i=0;i<n;i++){
            if(!s.empty() && heights[s.top()]>heights[i]){
                while(!s.empty() && heights[s.top()]>heights[i]){
                    int top = s.top();
                    s.pop();
                    int r = i;
                    int l = -1;
                    if(!s.empty()){
                        l = s.top();
                    }
                    res = max(res,heights[top]*(r-l-1));
                }
            }
            s.push(i);
        }
        while(!s.empty()){
            int top = s.top();
            s.pop();
            int r = n;
            int l = -1;
            if(!s.empty()){
                l = s.top();
            }
            res = max(res,heights[top]*(r-l-1));
        }
        return res;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        int maxArea = 0;
        vector<int> heights(matrix[0].size());
        for(int i=0;i<matrix[0].size();i++){
            heights[i] = matrix[0][i] - '0';
        }
        maxArea = max(maxArea,largestRectangleArea(heights));
        for(int i = 1;i<matrix.size();i++){
            for(int j = 0; j<matrix[i].size();j++){
                if(matrix[i][j] == '0'){
                    heights[j] = 0;
                }
                else{
                    heights[j]++;
                }
            }
            maxArea = max(maxArea,largestRectangleArea(heights));
        }
        return maxArea;
    }
};