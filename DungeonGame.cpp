class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int r, c;
        r = dungeon.size();
        if (r == 0 || dungeon[0].size() == 0) return 0;
        c = dungeon[0].size();
        pair<int, int> dp[r][c];
        int maxi = 0;
        for (int i = r - 1; i >= 0; i--) {
            for (int j = c - 1; j >= 0; j--) {
                int diff;
                if (i == r - 1) {
                    if (j == c - 1) {
                        if (dungeon[i][j] <= 0) {
                            dp[i][j] = make_pair(abs(dungeon[i][j]) + 1, 1);
                        } else {
                            dp[i][j] = make_pair(1, 1 + dungeon[i][j]);
                        }
                    } else {
                        if (dungeon[i][j] <= 0) {
                            diff = abs(dungeon[i][j]);
                            dp[i][j] = make_pair(dp[i][j + 1].first + diff, dp[i][j + 1].first);
                        } else {
                            if (dp[i][j + 1].first > dungeon[i][j])
                                dp[i][j] = make_pair(dp[i][j + 1].first - dungeon[i][j], 
                                                     dp[i][j + 1].first);
                            else
                                dp[i][j] = make_pair(1, 1 + dungeon[i][j]);
                        }
                    }
                } else if (j == c - 1) {
                    if (dungeon[i][j] <= 0) {
                        diff = abs(dungeon[i][j]);
                        dp[i][j] = make_pair(dp[i + 1][j].first + diff, dp[i + 1][j].first);
                    } else {
                        if (dp[i + 1][j].first > dungeon[i][j])
                            dp[i][j] = make_pair(dp[i + 1][j].first - dungeon[i][j], dp[i + 1][j].first);
                        else
                            dp[i][j] = make_pair(1, 1 + dungeon[i][j]);
                    }
                } else {
                    int mini = min(dp[i][j + 1].first, dp[i + 1][j].first);
                    if (dungeon[i][j] <= 0) {
                        diff = abs(dungeon[i][j]);
                        dp[i][j] = make_pair(mini + diff, mini);
                    } else {
                        if (mini > dungeon[i][j])
                            dp[i][j] = make_pair(mini - dungeon[i][j], mini);
                        else
                            dp[i][j] = make_pair(1, 1 + dungeon[i][j]);
                    }
                }
            }
        }
        
        return dp[0][0].first;
    }
};
