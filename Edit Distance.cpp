class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        int mem[m+1][n+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0)
                    mem[i][j] = j;
                else if(j==0) 
                    mem[i][j] = i;
                else if (word1[i-1]==word2[j-1]) 
                    mem[i][j]=mem[i-1][j-1];
                else 
                    mem[i][j] = 1 + min(mem[i-1][j-1],min(mem[i-1][j],mem[i][j-1]));
            }
        }
        return mem[m][n];
    }
};