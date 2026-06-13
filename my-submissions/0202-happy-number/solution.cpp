class Solution {
public:
    int nextNumber(int num) {
        int sum = 0;
        while(num > 0) {
            int rem = num % 10;
            num /= 10;
            sum += (rem * rem);
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do {
            slow = nextNumber(slow);
            fast = nextNumber(nextNumber(fast));
        } while(slow != fast);

        return slow == 1;
    }
};
