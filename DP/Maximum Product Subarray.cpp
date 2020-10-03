class Solution {
public:
    int maxProduct(vector<int>& nums) {
    int res =  nums[0];
    int i = 1, imax = res, imin = res;
    for (; i < nums.size(); i++) {
        if (nums[i] < 0)
            swap(imax, imin);
        imax = max(nums[i], imax * nums[i]);
        imin = min(nums[i], imin * nums[i]);
        res = max(res, imax);
    }
    return res;
    }
};