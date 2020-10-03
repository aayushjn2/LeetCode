class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
       vector<bool> mem(n,false);
       mem[n-1] = true;
       for(int i=n-2;i>=0;i--){
           int r_I = min(i + nums[i], n-1);
           for(int j = i+1;j<=r_I;j++){
               if(mem[j] == true){
                   mem[i] = true;
                   break;
               }
           }
       }
       return mem[0];
    }
};