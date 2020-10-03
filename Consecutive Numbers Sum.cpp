class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int res = 0;
        int k = 1;
        while(k<(ceil(sqrt(2*N)))){
            int t = k*(k-1)/2;
            if((N-t)%k==0){
                res++;
            }
            k++;
        }
        return res;
    }
};