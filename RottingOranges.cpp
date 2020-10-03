class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int totalOranges = 0;
        queue<pair<int,int> > q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == 1){
                    totalOranges++;
                }
                else if(grid[i][j] == 2){
                    totalOranges ++;
                    q.push({i,j});
                }
            }
        }
        if(totalOranges == 0){
            return 0;
        }
        int res = -1;
        while(!q.empty()){
            int queueSize = q.size();
            res++;
            while(queueSize !=0){
                pair<int,int> front = q.front();
                q.pop();
                queueSize--;
                int i = front.first, j = front.second;
                if(i-1 >= 0 && j >= 0 && i < grid.size() && j < grid[i-1].size() && grid[i-1][j] == 1){
                    grid[i-1][j] = 2;
                    q.push({i-1,j});
                }
                if(i >= 0 && j >= 0 && i+1 < grid.size() && j < grid[i+1].size() && grid[i+1][j] == 1){
                    grid[i+1][j] = 2;
                    q.push({i+1,j});
                }
                if(i >= 0 && j - 1 >= 0 && i < grid.size() && j < grid[i].size() && grid[i][j-1] == 1){
                    grid[i][j-1] = 2;
                    q.push({i,j-1});
                }
                if(i >= 0 && j >= 0 && i < grid.size() && j+1 < grid[i].size() && grid[i][j+1] == 1){
                    grid[i][j+1] = 2;
                    q.push({i,j+1});
                }
                totalOranges --;   
            }
        }
        if(totalOranges !=0){
            return -1;
        }
        return res;
    }
};