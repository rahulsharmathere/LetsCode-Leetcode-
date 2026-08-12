class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int sr = entrance[0];
        int sc = entrance[1];

        q.push({{sr, sc}, 0});
        vis[sr][sc] = 1;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [pos, dist] = q.front();
            q.pop();

            int r = pos.first;
            int c = pos.second;

            if ((r != sr || c != sc) &&
                (r == 0 || r == n - 1 || c == 0 || c == m - 1)) {
                return dist;
            }

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    maze[nr][nc] == '.' &&
                    !vis[nr][nc]) {

                    vis[nr][nc] = 1;
                    q.push({{nr, nc}, dist + 1});
                }
            }
        }

        return -1;
    }
};