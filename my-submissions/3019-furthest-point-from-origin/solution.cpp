class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int countL = 0;
        int countR = 0;
        int countU = 0;

        for(int i = 0; i < moves.size(); i++) {
            if(moves[i] == 'R') {
                countR++;
            } else if(moves[i] == 'L') {
                countL++;
            } else {
                countU++;
            }
        }
        return abs(countR - countL) + countU;
    }
};
