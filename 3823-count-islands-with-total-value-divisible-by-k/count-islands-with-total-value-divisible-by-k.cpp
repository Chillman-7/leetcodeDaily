class Solution {
public:
    vector<pair<int,int>>directions = {{0,-1},{-1,0},{0,1},{1,0}};

    long long dfs(vector<vector<int>>& grid,int i,int j){
        int n = grid.size();
        int m = grid[0].size();

        long long sum=grid[i][j];
        grid[i][j]=0;

        for(auto dir:directions){
            int i_dir = i+dir.first;
            int j_dir = j+dir.second;

            if(i_dir >= 0 && i_dir < n && j_dir >= 0 && j_dir < m && grid[i_dir][j_dir] > 0){
                sum+=dfs(grid,i_dir,j_dir);
            }

        }
        return sum;

        
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        long long sum=0;
        int cnt =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){
                    sum = dfs(grid,i,j);
                    if(sum%k == 0){
                        cnt++;
                    }
                }
            }
        }
        return cnt;

    }
};