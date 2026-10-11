class Solution {
public:
    vector<long long> fib = {0, 1};
    
    bool threeFibonacciSum(int n) {
        while(fib.back() < n) {
            int sz = fib.size();
            fib.push_back(fib[sz - 1] + fib[sz - 2]);
        }

        for(int i = 0; i < fib.size() - 2; i++) {
            int sum = fib[i] + fib[i + 1] + fib[i + 2];
            if(sum == n) return true;
            if(sum > n) return false;
        }
        
        return false;
    }
};
