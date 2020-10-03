class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxSum = 0;
        int n = cardPoints.size();
        if(k>=n){
            for(int i=0;i<n;i++){
                maxSum +=cardPoints[i];
            }
            return maxSum;
        }
        for(int i=0;i<k;i++){
            maxSum +=cardPoints[i];
        }
        int val = maxSum;
        for(int i=n-1;i>=n-k;i--){
            val = val+cardPoints[i]-cardPoints[i-n+k];
            if(maxSum< val){
                maxSum = val;
            }
        }
        return maxSum;
    }
};