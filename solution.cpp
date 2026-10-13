class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fror = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    fror++;
                }
            }
        }

        bool change = true;
        int min = 0;
        while(change){
            change = false;
            for(int i = 0; i < grid.size(); i++){
                for(int j = 0; j < grid[0].size(); j++){
                    if (grid[i][j] == 1) {
                        if ((i + 1 < grid.size() && grid[i + 1][j] == 2) ||
                            (i - 1 >= 0 && grid[i - 1][j] == 2) ||
                            (j + 1 < grid[0].size() && grid[i][j + 1] == 2) ||
                            (j - 1 >= 0 && grid[i][j - 1] == 2)) {

                            grid[i][j] = 3;
                            fror--;
                            change = true;
                        }
                    }
                }
            }

            for(int i = 0; i < grid.size(); i++){
                for(int j = 0; j < grid[0].size(); j++){
                    if (grid[i][j] == 3) {
                        grid[i][j] = 2;
                    }
                }
            }

            min++;
        }

        if(fror == 0) return min - 1;

        return -1;
    }
};
