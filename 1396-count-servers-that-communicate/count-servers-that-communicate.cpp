class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>indexRowCount(n,0);
        vector<int>indexColCount(m,0);


        //save maad yell ones barthaav.
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    indexColCount[j]+=1;
                    indexRowCount[i]+=1;
                }
            }
        }

        int resultServers=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && (indexRowCount[i]>1 || indexColCount[j]>1)){
                    resultServers+=1;
                }
            }
        }
        return resultServers;





    }
};