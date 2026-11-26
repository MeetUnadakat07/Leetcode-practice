class Solution {
public:
    bool canAliceWin(int n) {
        int remove = 10;
        int turns = 0;

        while(remove <= n) {
            n -= remove;
            remove--;
            turns++;
        }
        return (turns % 2);
    }
};
