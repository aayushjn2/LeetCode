class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n = nums.size();
        for(int i =0;i<n;i++)
            sum += nums[i];
        if(sum%2==1)
            return false;
        else{
            sum = sum/2;
            bool mem[n+1][sum+1];
            for(int i=0;i<=n;i++)
                mem[i][0] = true;
            for(int i=0;i<=sum;i++)
                mem[0][i] = false;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=sum;j++){
                    if(j<nums[i-1])
                        mem[i][j] = mem[i-1][j];
                    else
                        mem[i][j] = mem[i-1][j] || mem[i-1][j-nums[i-1]];
                }
            }
            return mem[n][sum];
        }
    }
};