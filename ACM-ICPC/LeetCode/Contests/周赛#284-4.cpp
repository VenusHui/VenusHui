// 6032. 得到要求路径的最小带权子图
// wls做法
class Solution
{
private:
    long long f[3][100001];
    struct node
    {
        int v, y;
    };
    vector<node> edge[2][100001];
    set<pair<long long, int>> v;

    inline void dijsktra(int n, int s, int i1, int i2)
    {
        memset(f[i1], 127, sizeof(f[i1]));
        f[i1][s] = 0;
        for (int i = 0; i < n; i++)
            v.insert(make_pair(f[i1][i], i));
        for (; v.size();)
        {
            int x = v.begin()->second;
            if (f[i1][x] > 1LL << 60LL)
                break;
            v.erase(v.begin());
            for (auto y : edge[i2][x])
            {
                if (f[i1][x] + y.v < f[i1][y.y])
                {
                    v.erase(make_pair(f[i1][y.y], y.y));
                    f[i1][y.y] = f[i1][x] + y.v;
                    v.insert(make_pair(f[i1][y.y], y.y));
                }
            }
        }
    }

public:
    long long minimumWeight(int n, vector<vector<int>> &edges, int src1, int src2, int dest)
    {
        for (auto i : edges)
        {
            node x;
            x.v = i[2];
            x.y = i[1];
            edge[0][i[0]].push_back(x);
            x.y = i[0];
            edge[1][i[1]].push_back(x);
        }
        dijsktra(n, src1, 0, 0);
        dijsktra(n, src2, 1, 0);
        dijsktra(n, dest, 2, 1);
        long long ans = 1LL << 60LL;
        for (int i = 0; i < n; i++)
        {
            if (f[0][i] < 1LL << 60LL && f[1][i] < 1LL << 60LL && f[2][i] < 1LL << 60LL)
                ans = min(ans, f[0][i] + f[1][i] + f[2][i]);
        }
        if (ans < 1LL << 60LL)
            return ans;
        else
            return -1;
    }
};