class Solution {
public:
    int bulbSwitch(int n) {
        //no of divisors
        //odd no of divisors:bulb on
        //even no of divisors:bulb off
        //onyl perfect squares have odd no of divisors, 1^2,2^2,3^2,4^2...
        return sqrt(n);
    }
};