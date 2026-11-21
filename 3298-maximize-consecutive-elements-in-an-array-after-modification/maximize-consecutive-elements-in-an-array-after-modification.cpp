class Solution {
public:
int n;
vector<vector<int>> dp;

    int findMethod(int start,int target,vector<int>& nums){

        int j = lower_bound(nums.begin()+start,nums.end(),target) - nums.begin();
        if(j<n && nums[j] == target){
            return j;
        }
        return -1;

    }

    int solve(int i,int inc ,vector<int>& nums){
        
        int currVal = nums[i]+inc; //inc -> 0 or 1
        int len=1;
        
        //1st option
        int j = findMethod(i+1,currVal+1,nums);
        if(j!=-1){
            len = max(len,1 + solve(j,0,nums));
        }
        if (dp[i][inc] != -1) return dp[i][inc];
        
        //2nd option -> find currVal and then inc by 1
        j = findMethod(i+1,currVal,nums);
        if(j!=-1){
            len = max(len,1+solve(j,1,nums));
        }
        
        return dp[i][inc] = len;

    }
    int maxSelectedElements(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, vector<int>(2, -1));
        int result =1;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
          result = max({result,solve(i,0,nums),solve(i,1,nums)});
        }
        return result;
    }
};