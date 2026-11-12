class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int decLength=1;
        int incLength=1;
        int best=1;

        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                incLength+=1;
                decLength=1;
            }
            else if(nums[i-1]>nums[i]){
                decLength+=1;
                incLength=1;
            }else{
                decLength=1;
                incLength=1;
            }
            best = max({best,incLength,decLength});
        }
        return best;
    }
};