class Solution {
public:
    
    vector<int> memo;

    int solve(int i,int n,vector<int>& costs){
        if(i==n)return 0;
        if(memo[i]!=-1)return memo[i];

        int cost = INT_MAX;

        int j= i+1;
        if(j<=n){
            cost = costs[j-1]+(j-i)*(j-i) + solve(j,n,costs);

        }
         j= i+2;
        if(j<=n){
            cost = min(cost,costs[j-1]+(j-i)*(j-i) + solve(j,n,costs));

        }
        j= i+3;
        if(j<=n){
            cost = min(cost,costs[j-1]+(j-i)*(j-i) + solve(j,n,costs));

        }
        return memo[i] = cost;
    }
    
    int climbStairs(int n, vector<int>& costs) {
        memo.assign(n+1,-1);
        return solve(0,n,costs);

    }
};