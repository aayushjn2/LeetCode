class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        int lis[n];
        lis[0]=1;
        int res=lis[0];
        for(int i=1;i<n;i++){
            lis[i]=1;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && lis[i]<lis[j]+1){
                    lis[i] = lis[j]+1;
                    if(res<lis[i])res=lis[i];
                }
            }
        }
        return res;
    }
};