class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int edges = prerequisites.size();
        vector<vector<int>> g(numCourses);
        vector<int> indegree(numCourses,0);
        for(int i=0;i<edges;i++){
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]+=1;
        }
        return kahnsAlgo(g, numCourses, indegree);
    }
private:
    vector<int> kahnsAlgo(vector<vector<int>>& g,int N, vector<int>& indegree){
        int count = 0;
        vector<int> res;
        queue<int> q;
        for(int i=0;i<N;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto v: g[u]){
                indegree[v]--;
                if(indegree[v]==0)
                    q.push(v);
            }
            res.push_back(u);
            count++;
        }
        if(count!=N)
            return vector<int>();
        return res;
    }
};