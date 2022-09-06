// 1184. 公交站间的距离
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int size = distance.size();
        int ans = 1e9 + 1, tmp = 0, s = start;
        while (s != destination) {
            tmp += distance[s % size];
            s = (s + 1 + size) % size;
        }
        ans = min(ans, tmp);
        tmp = 0, s = start;
        while (s != destination) {
            s = (s - 1 + size) % size;
            tmp += distance[s % size];
        }
        ans = min(ans, tmp);
        return ans;
    }
};