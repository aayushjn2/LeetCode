class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0) return 0;
        int count  = 0;
        unordered_map<int,int> mem;
        for(auto x : nums){
            mem[x]++;
        }
        if(k == 0){
            for(auto pair : mem){
                if(pair.second > 1){
                    count++;
                }
            }
        }
        else{
            for(auto pair : mem){
                if( mem.find( pair.first + k) != mem.end()){
                    count++;
                }
            }
        }
        return count;
    }
};