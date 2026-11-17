class Solution {
public:
 
    int solve(int i,int j,vector<vector<int>>& grid,int xr,vector<vector<vector<int>>>& dp){
        int n = grid.size();
        int m = grid[0].size();
        //BASE CASE
        if(i>=n || j>=m){
            return 1e9;
        }
        xr =xr^ grid[i][j];
        //REACHED END
        if(i==n-1 && j==m-1){
            return xr;
        }
        if(dp[i][j][xr]!=-1){
            return dp[i][j][xr];
        }

        int right = solve(i,j+1,grid,xr,dp);
        int down = solve(i+1,j,grid,xr,dp);

        return dp[i][j][xr]=min(right,down);
    }

    
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(1024,-1)));
        return solve(0,0,grid,0,dp);
    }
};