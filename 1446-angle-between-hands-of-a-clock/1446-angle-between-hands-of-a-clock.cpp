#include<cmath>
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hrs = (hour%12) + (double)minutes/60;
        double h = hrs*30;

        double m = (minutes*6);

        double ans = abs(m-h);

        if(ans > 180){
            ans = 360 - ans;
        }

        return ans;

    }
};