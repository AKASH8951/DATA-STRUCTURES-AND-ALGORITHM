class Solution {
public:
    bool checkDivisibility(int n) {
        int x = n , sum = 0;
        int product = 1;

        while(n) {
            int digit = n % 10;
            sum = sum  + digit; 
            product *= digit;
            n = n/10;
        }

        if(x % (sum + product) == 0) {
            return true;
        }
        else {
            return false;
        }
    }
};