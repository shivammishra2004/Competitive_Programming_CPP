/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 */

// @lc code=start
class Solution {
public:

    int N,M;
    void bfs(vector<vector<int>>&grid, vector<vector<int>> &vis,queue<pair<int,int>> q){
        for(auto i:q.front()){
            int drow = q.front().first;
            int dcol = q.front().second;
            q.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nrow= drow+i;
                    int ncol = dcol+j;
                    if(abs(i) != abs(j) && nrow>=0 && nrow <N && ncol >=0 && ncol <M){
                        if(vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                            vis[nrow][ncol] =1;
                            tminus++;
                            q.push({nrow,ncol});
                        }
                    }
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>> vis(N,vector<int>(M,0));
        queue<pair<int,int>> q;
        int total=0,tminus=0   ;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(!i || !j || j=M-1 || i == N-1){
                    if(vis[i][j] == 0 && grid[i][j] == 1){
                        vis[i][j] = 1;
                        tminus++;
                        q.push({i,j});
                    }
                }
                if(grid[i][j] ==1) total++;
            }
        }
        bfs(grid,vis,q);
        return total-tminus;
    }
};
// @lc code=end

