class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        high = sum(nums)
        low = max(nums)
        res = low
        while low<=high:
            mid = low + (high-low)//2
            cnt_m = sum_m = 0
            for num in nums:
                sum_m += num
                if sum_m > mid:
                    cnt_m +=1
                    sum_m = num
            cnt_m +=1
            if(cnt_m == m):
                res = mid
                high = mid - 1
            elif (cnt_m < m):
                high = mid - 1
            else:
                low = mid + 1
        return res