class Solution {
    public:
        double myPow(double x, int n) {
            if (n == 0) return 1;
            if (x == 1) return 1;
    
            if (n == INT_MIN) {
                x = 1 / x;
                return myPow(x * x, -(n / 2));  // Use n/2 to stay within bounds
            }
    
            if (n < 0) { 
                x = 1 / x;
                n = -n;
            }
            
            double half = myPow(x, n / 2);
            
            if (n % 2 == 0) return half * half;
            else return x * half * half;
        }
    };