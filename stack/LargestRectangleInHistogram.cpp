#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    if(!heights)
        return 0;
    int n = heights.size();
    int res = 0;
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
                int area = heights[top]*(r-l-1);
                res = max(res,area);
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
        int area = heights[top]*(r-l-1);
        res = max(res,area);
    }
    return res;
}

int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int maxArea = largestRectangleArea(v);
    cout<<maxArea<<endl;
    return 0;
}