class Solution {
public:

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> temp(m, vector<int>(n));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp[j][n-1-i] = grid[i][j];
            }
        }

        return temp;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {

        long long total = 0;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                total += grid[i][j];
            }
        }

        for(int rot = 0; rot < 4; rot++){

            n = grid.size();
            m = grid[0].size();

            if(n < 2){
                grid = rotateGrid(grid);
                continue;
            }

            unordered_set<long long> st;
            st.insert(0);

            long long sum = 0;

            // -------- SINGLE COLUMN --------
            if(m == 1){
                for(int i=0;i<n-1;i++){
                    sum += grid[i][0];

                    long long x = 2*sum - total;

                    if(x == 0 || x == grid[0][0] || x == grid[i][0]){
                        return true;
                    }
                }
                grid = rotateGrid(grid);
                continue;
            }

            // -------- GENERAL CASE --------
            for(int i=0;i<n-1;i++){

                for(int j=0;j<m;j++){
                    sum += grid[i][j];
                    st.insert(grid[i][j]);
                }

                long long x = 2*sum - total;

                // first row special case
                if(i == 0){
                    if(x == 0 || x == grid[0][0] || x == grid[0][m-1]){
                        return true;
                    }
                }
                else{
                    if(st.count(x)) return true;
                }
            }

            grid = rotateGrid(grid);
        }

        return false;
    }
};