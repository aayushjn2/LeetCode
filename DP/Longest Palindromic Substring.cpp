class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n==0 || n==1)
            return s;
        int low,high,maxLength=1,start=0;
        for(int i=1;i<n;i++){
            low=i-1;
            high=i;
            while(low>=0 && high<n && s[low]==s[high]){
                if(maxLength<high-low+1){
                    start=low;
                    maxLength = high-low+1;
                }
                --low;
                ++high;
            }
            low=i-1;
            high=i+1;
            while(low>=0 && high<n && s[low]==s[high]){
                if(maxLength<high-low+1){
                    start=low;
                    maxLength = high-low+1;
                }
                --low;
                ++high;
            }
        }
        string res="";
        for(int i=start;i<start+maxLength;i++)
            res +=s[i];
        return res;
    }
};