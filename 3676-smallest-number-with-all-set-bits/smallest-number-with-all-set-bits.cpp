class Solution {
public:
    int smallestNumber(int n) {
        int temp = n;
        if ((n & (n + 1)) == 0)
            return n;
        int bits = 0;
        while(temp) {
            bits++;
            temp = temp >> 1;
        }
        return (1 << bits) - 1;
    }
};