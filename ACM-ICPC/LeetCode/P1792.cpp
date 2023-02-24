// 1792. 最大平均通过率
class Solution {
private:
    int size = 0;
    vector<pair<vector<int>, double>> heap;
    inline void up(int x) {
        while (x / 2 != 0 && heap[x / 2].second < heap[x].second) {
            swap(heap[x / 2], heap[x]);
            x /= 2;
        }
    }
    inline void down(int x) {
        int t = x;
        while (x * 2 < size && heap[x * 2].second > heap[t].second) t = x * 2;
        while (x * 2 + 1 < size && heap[x * 2 + 1].second > heap[t].second) t = x * 2 + 1;
        if (t != x) swap(heap[x], heap[t]), down(t);
    }
    inline void insert(pair<vector<int>, double> x) {
        size++;
        if (heap.size() > size) heap[size] = x;
        else heap.push_back(x);
        up(size);
    }
    inline void remove(int x) {
        swap(heap[x], heap[size--]);
        up(x), down(x);
    }
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        heap.resize(1);
        for (auto& e : classes) {
            insert(make_pair(e, 1.0 * (e[0] + 1) / (e[1] + 1) - 1.0 * e[0] / e[1]));
        }
        while (extraStudents--) {
            pair<vector<int>, double> cnt = heap[1];
            remove(1);
            cnt.first[0]++, cnt.first[1]++;
            cnt.second = 1.0 * (cnt.first[0] + 1) / (cnt.first[1] + 1) - 1.0 * cnt.first[0] / cnt.first[1];
            insert(cnt);
        }
        double ans = 0;
        for (int i = 1; i <= size; i++) {
            ans += 1.0 * heap[i].first[0] / heap[i].first[1];
        }
        return ans / size;
    }
};