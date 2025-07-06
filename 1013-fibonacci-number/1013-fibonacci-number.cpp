class Solution {
public:
    int fib(int n) {

        if(n == 0){
            return 0;
        }


        int p2 = 1;
        int p1 = 1;
        int curr;


        for(int i = 1; i < n; i++){
            curr = p2+p1;
            p2 = p1;
            p1 = curr;
        }

        return p2;


    }
};