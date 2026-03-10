#define MOD 12345

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int total = rows * cols;
        vector<int> flat(total);
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                flat[r * cols + c] = grid[r][c];
            }
        }

        vector<int> pref(total), suff(total);

        pref[0] = 1;
        for(int i = 1; i < total; i++){
            pref[i] = (1LL * pref[i-1] * flat[i-1]) % MOD;
        }

        suff[total-1] = 1;
        for(int i = total-2; i >= 0; i--){
            suff[i] = (1LL * suff[i+1] * flat[i+1]) % MOD;
        }

        vector<vector<int>> result(rows, vector<int>(cols));
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                int idx = r * cols + c;
                result[r][c] = (pref[idx] * suff[idx]) % MOD;
            }
        }

        return result;
    }
};