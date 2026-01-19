class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> row(n, vector<int>(m, 0));
        vector<vector<int>> col(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            row[i][0] = mat[i][0];
        }

        for(int j = 0; j < m; j++) {
            col[0][j] = mat[0][j];
        }

        for(int i = 0; i < n; i++) {
            for(int j = 1; j < m; j++) {
                row[i][j] = mat[i][j] + row[i][j-1];
            }
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                col[i][j] = mat[i][j] + col[i-1][j];
            }
        }

        int ans = 0;

        for(int k = 1; k <= min(n, m); k++) {
            bool found = false;

            for(int i = 0; i + k - 1 < n; i++) {
                for(int j = 0; j + k - 1 < m; j++) {

                    int sum = 0;

                    for(int r = i; r < i + k; r++) {
                        int right = row[r][j + k - 1];
                        int left = (j > 0 ? row[r][j - 1] : 0);
                        sum += (right - left);
                    }

                    if(sum <= threshold) {
                        found = true;
                        break;
                    }
                }
                if(found) break;
            }

            if(found) ans = k;
            else break;
        }

        return ans;
    }
};