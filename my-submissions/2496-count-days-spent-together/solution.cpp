class Solution {
public:
    vector<int> month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int getDays(string date) {
        int m = stoi(date.substr(0, 2));
        int d = stoi(date.substr(3, 2));

        for(int i = 0; i < m - 1; i++) {
            d += month[i];
        }
        return d;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aliceStart = getDays(arriveAlice);
        int bobStart = getDays(arriveBob);
        int aliceEnd = getDays(leaveAlice);
        int bobEnd = getDays(leaveBob);

        int st = max(aliceStart, bobStart);
        int end = min(aliceEnd, bobEnd);

        return max(0, end - st + 1);
    }
};
