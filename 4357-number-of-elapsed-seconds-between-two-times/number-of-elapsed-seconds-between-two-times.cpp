class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int sec1 = stoi(startTime.substr(6,2));
        int min1 = 60 * stoi(startTime.substr(3,2));
        int h1 = 60 * 60 * stoi(startTime.substr(0,2));
        int sec2 = stoi(endTime.substr(6,2));
        int min2 = 60 * stoi(endTime.substr(3,2));
        int h2 = 60 * 60 * stoi(endTime.substr(0,2));
        int ans = h2-h1 + min2-min1 + sec2-sec1;
        return ans;
    }
};