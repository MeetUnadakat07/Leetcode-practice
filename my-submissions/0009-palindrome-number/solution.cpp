class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int n = x;
        long int revNum = 0;
        while(x>0)
        {
            int rem = x%10;
            revNum = revNum*10+rem;
            x/=10;
        }
        return revNum == n;
    }
};
