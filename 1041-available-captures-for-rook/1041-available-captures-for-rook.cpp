class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int rookCol=0;
        int rookRow=0;
        int ans=0;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                if(board[i][j]=='R')
                {
                    rookRow=i;
                    rookCol=j;
                }
            }
        }
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int d = 0; d < 4; d++) {
            int x = rookRow + dx[d];
            int y = rookCol + dy[d];

            while (x >= 0 && x < 8 && y >= 0 && y < 8) {

                if (board[x][y] == 'B')
                    break;

                if (board[x][y] == 'p') {
                    ans++;
                    break;
                }

                x += dx[d];
                y += dy[d];
            }
        }

        return ans;

    }
};