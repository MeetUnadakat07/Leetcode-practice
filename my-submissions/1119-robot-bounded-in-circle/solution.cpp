class Solution {
public:
    bool isRobotBounded(string instructions) {
        char dir = 'N';
        int x = 0, y = 0;
        for(char c : instructions) {
            if(c == 'G') {
                if(dir == 'N') {
                    y++;
                } else if(dir == 'S') {
                    y--;
                } else if(dir == 'E') {
                    x++;
                } else {
                    x--;
                }
            } else if(c == 'L') {
                if(dir == 'N') {
                    dir = 'W';
                } else if(dir == 'S') {
                    dir = 'E';
                } else if(dir == 'E') {
                    dir = 'N';
                } else {
                    dir = 'S';
                }
            } else {
                if(dir == 'N') {
                    dir = 'E';
                } else if(dir == 'S') {
                    dir = 'W';
                } else if(dir == 'E') {
                    dir = 'S';
                } else {
                    dir = 'N';
                }
            }
        }
        return (dir != 'N' || (x == 0 && y == 0));
    }
};
