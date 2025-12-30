class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if (n < 3 || m < 3) return 0;
        int ans=0;
        // rahul, find no of 3*3 magic squares
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                //starting pt of square
                bool allGood=true;
                vector<bool>used(10,false);
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        int v = grid[i + x][j + y];
                        if (v < 1 || v > 9 || used[v]) {
                            allGood = false;
                            break;
                        }
                        used[v] = true;
                    }
                    if (!allGood) break;
                }
                if(!allGood)continue;
                int s=grid[i][j]+grid[i][j+1]+grid[i][j+2];
                for (int x = 0; x < 3; x++)
                    if (grid[i+x][j] + grid[i+x][j+1] + grid[i+x][j+2] != s) allGood = false;
                for (int y = 0; y < 3; y++)
                    if (grid[i][j+y] + grid[i+1][j+y] + grid[i+2][j+y] != s) allGood = false;
                if (grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2] != s) allGood = false;
                if (grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j] != s) allGood = false;

                if (allGood) ans++;

            }
        }
        return ans;
    }
};