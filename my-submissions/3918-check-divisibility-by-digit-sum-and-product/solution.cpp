class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, prod = 1;
        int num = n;
        while(num > 0) {
            int rem = num % 10;
            sum += rem;
            prod *= rem;
            num /= 10;
        }
        cout << sum << " " << prod << endl;
        return (n % (sum + prod)) == 0;
    }
};
