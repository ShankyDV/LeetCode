class Solution {
private:
    struct Point {
        int x;
        int y;
        Point(int x_, int y_) : x(x_), y(y_) {}
    };
public:
    void solve(vector<vector<char>> &board) {
        if (board.empty() || board[0].empty()) return;
        //list<Point> path;  // bidirectional linked list is good? maybe
        vector<Point> path;
        vector<Point> pathAlt;
        int rows = board.size();
        int cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O') {
                path.push_back(Point(i, 0));
                board[i][0] = 'B';
            }
            if (board[i][cols-1] == 'O') {
                path.push_back(Point(i, cols-1));
                board[i][cols-1] = 'B';
            }
        }
        for (int i = 0; i < cols; i++) {
            if (board[0][i] == 'O') {
                path.push_back(Point(0, i));
                board[0][i] = 'B';
            }
            if (board[rows-1][i] == 'O') {
                path.push_back(Point(rows-1, i));
                board[rows-1][i] = 'B';
            }
        }
        while (!path.empty()) {
            Point p = path.back();
            path.pop_back();
            if (p.x + 1 < board.size() && board[p.x+1][p.y] == 'O') {
                board[p.x+1][p.y] = 'B';
                pathAlt.push_back(Point(p.x+1, p.y));
            }
            if (p.y + 1 < board[p.x].size() && board[p.x][p.y+1] == 'O') {
                board[p.x][p.y+1] = 'B';
                pathAlt.push_back(Point(p.x, p.y+1));
            }
            if (p.x > 0 && board[p.x-1][p.y] == 'O') {
                board[p.x-1][p.y] = 'B';
                pathAlt.push_back(Point(p.x-1, p.y));
            }
            if (p.y > 0 && board[p.x][p.y-1] == 'O') {
                board[p.x][p.y-1] = 'B';
                pathAlt.push_back(Point(p.x, p.y-1));
            }
            if (path.empty()) {
                swap(path, pathAlt);
                pathAlt.clear();
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'B') {
                    board[i][j] = 'O';  // Welcome back.
                }
            }
        }
    }
};