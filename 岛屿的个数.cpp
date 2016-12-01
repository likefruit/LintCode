class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
     void change(vector<vector<bool>>& grid,int i,int j)
     {
         grid[i][j]=false;
         int m=grid.size();
         int n=grid[0].size();
         if(i>0&&grid[i-1][j]==true)
                change(grid,i-1,j);
         if(i<m-1&&grid[i+1][j]==true)
                change(grid,i+1,j);
         if(j>0&&grid[i][j-1]==true)
                change(grid,i,j-1);
         if(j<n-1&&grid[i][j+1]==true)
                change(grid,i,j+1);
     }
    int numIslands(vector<vector<bool>>& grid) {
        // Write your code here
        if (grid.empty()) {
            return 0;
        }
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]==true)
                {
                    count++;
                    change(grid,i,j);
                }
            }
        return count;
        
    }
};
