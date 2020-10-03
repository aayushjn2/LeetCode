class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int t_res=1;
        int res=1,i=1;
        int n = nums.size();
        if(n==0)return 0;
        for(;i<n;i++){
            if(nums[i]!=nums[i-1]){
                if(nums[i]-nums[i-1]==1)
                    t_res++;
                else{
                    res = max(res,t_res);
                    t_res = 1;
                }
            }
        }
        return max(res,t_res);
    }
};