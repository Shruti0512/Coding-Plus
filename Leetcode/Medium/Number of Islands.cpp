class Solution {
public:
    void path(vector<vector<char>>& grid, int x, int y, vector<vector<int> >& visited) {
        if (!visited[x][y]) {
            visited[x][y] = 1;
            
            int hor[4] = {1, -1, 0, 0};
            int vert[4] = {0, 0, 1, -1};

            for (int i = 0; i < 4; i++) {
                int hormov = hor[i] + y;
                int vermov = vert[i] + x;

                if (hormov < grid[0].size() && hormov >= 0 &&
                    vermov < grid.size() && vermov >= 0 &&
                    !visited[vermov][hormov] &&
                    grid[vermov][hormov] == '1') {
                    path(grid, vermov, hormov, visited);
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int> > visited(grid.size(), vector<int>(grid[0].size(), 0));
        int cont = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    cont+=1;
                    path(grid, i, j, visited);
                }
            }
        }
        return cont;
    }
};