// 2. 交通枢纽
class Solution {
private:
    const int maxn = 1001;
public:
    int transportationHub(vector<vector<int>>& path) {
        int size = path.size();
        set<int> st;
        vector<int> indeg(maxn), outdeg(maxn);
        for (int i = 0; i < size; i++) {
            st.insert(path[i][0]);
            st.insert(path[i][1]);
            indeg[path[i][1]]++;
            outdeg[path[i][0]]++;
        }
        int num = st.size();
        for (int i = 0; i < maxn; i++) {
            if (indeg[i] == num - 1 && outdeg[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};