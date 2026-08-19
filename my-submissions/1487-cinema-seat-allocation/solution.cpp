class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> seats;

        for(auto seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            if(!seats.count(row)) {
                seats[row] = vector<int> (10, 0);
            }

            seats[row][col - 1] = 1;
        }

        long long count = 0;

        count += 2LL * (n - seats.size());

        for(auto seat : seats) {
            bool left = seat.second[1] == 0 && seat.second[2] == 0 && seat.second[3] == 0 && seat.second[4] == 0;
            bool mid = seat.second[3] == 0 && seat.second[4] == 0 && seat.second[5] == 0 && seat.second[6] == 0;
            bool right = seat.second[5] == 0 && seat.second[6] == 0 && seat.second[7] == 0 && seat.second[8] == 0;

            if(left && right) {
                count += 2;
            } else if(left || mid || right) {
                count++;
            }
        }
        return (int) count;
    }
};
