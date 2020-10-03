class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if len(nums)==1:
            return nums
        if k==1:
            return nums
        n = len(nums)
        lmax = [0]*n
        rmax = [0]*n
        l = nums[0]
        r = nums[-1]
        rmax[-1] = r
        for i in range(1,n):
            if i%k == 0:
                l = nums[i]
            else:
                l = max(l,nums[i])
            lmax[i] = l
        for i in range(n-2,-1,-1):
            if (i+1)%k == 0:
                r = nums[i]
            else:
                r = max(r,nums[i])
            rmax[i] = r
        res = [0]*(n-k+1)
        for i in range(n-k+1):
            res[i] = max(rmax[i],lmax[i+k-1])
        return res