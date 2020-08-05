class Solution {
public:
    
    bool isMovePossible(vector<vector<int>> grid, int i, int j, int n, int m, vector<vector<int>> visited){
        // index of matrix
        if(i<0 || i>=n || j<0 || j>=m)
            return false;
        
        // not possible move or move visited
        else if(grid[i][j]==0 || visited[i][j]==1){
            return false;
        }
        
        return true;
    }
    
    void find(vector<vector<int>> grid, int x, int y, int n, int m, int &res){
        // base condition
        if(x==n || y==m)
            return;

        int globalAns=res;

        for(int i=x; i<n; i++){
            int localAns = 0;
            for(int j=y; j<m; j++){
                res += grid[i][j];

                int r1=0, r2=0, r3=0, r4=0;
                vector<vector<int>> visited(n, vector<int>(m, 0));

                // move
                if(isMovePossible(grid, i, j-1, n, m, visited)){
                    r1 = grid[i][j-1];
                    find(grid, i, j-1, n, m, res);
                }

                if(isMovePossible(grid, i-1, j, n, m, visited)){
                    r2 = grid[i-1][j];
                    find(grid, i-1, j, n, m, res);
                }

                if(isMovePossible(grid, i, j+1, n, m, visited)){
                    r3 = grid[i][j+1];
                    find(grid, i, j+1, n, m, res);
                }

                if(isMovePossible(grid, i+1, j, n, m, visited)){
                    r4 = grid[i+1][j];
                    find(grid, i+1, j, n, m, res); 
                }

                visited[i][j] = 1;
                return;   // backtracking
            }
            localAns = max(r1, max(r2, max(r3, r4)));
        }
        
        globalAns = max(globalAns, localAns);
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int res=0;
        find(grid, 0, 0, grid.size(), grid[0].size(), res);
        return res;
    }
    
};