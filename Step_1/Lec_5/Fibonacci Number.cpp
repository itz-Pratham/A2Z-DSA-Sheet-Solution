class Solution {
    public:
        int fib(int n) {
            if(n == 0) return 0;
            if(n == 1) return 1;
            if(n == 2) return 1;
            int a = 1;
            int b = 1;
            int next = a+b;
            n-=2;
            while(n>0){
                next = a+b;
                a=b;
                b=next;
                n--;
            }
    
            return next;
        }
    };