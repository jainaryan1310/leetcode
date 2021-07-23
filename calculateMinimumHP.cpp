class Solution {
public:
  vector<vector<int>> minHP;
  int m;
  int n;
  int MAX = 1000000;

  int solve(vector<vector<int>>& dungeon, int i, int j) {
    if (minHP[i][j] != MAX) {
      return minHP[i][j];
    } else if (i == m - 1 && j == n - 1) {
      if (dungeon[i][j] > 0) {
        minHP[i][j] = 1;
      } else {
        minHP[i][j] = -dungeon[i][j] + 1;
      }
      return minHP[i][j];
    } else {
      int minRight = MAX;
      int minDown = MAX;
      if (i < m - 1) {
        minDown = solve(dungeon, i + 1, j);
      }
      if (j < n - 1) {
        minRight = solve(dungeon, i, j + 1);
      }
      if ((min(minRight, minDown) - dungeon[i][j]) < 1) {
        minHP[i][j] = 1;
      }else{
        minHP[i][j] = (min(minRight, minDown) - dungeon[i][j]);
      }
      return minHP[i][j];
    }
  }

  int calculateMinimumHP(vector<vector<int>>& dungeon) {

    m = dungeon.size();
    n = dungeon[0].size();

    vector<int> empty;
    for (int i = 0; i < n; i++) {
      empty.push_back(MAX);
    }
    for (int i = 0; i < m; i++)
    {
      minHP.push_back(empty);
    }

    return solve(dungeon, 0, 0);

  }
};