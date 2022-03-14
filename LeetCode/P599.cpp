// 599. 两个列表的最小索引总和
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<pair<int, string> > ans;
        int size1 = list1.size(), size2 = list2.size();
        for (int i = 0; i < size2; i++)
        {
            for (int j = 0; j < size1; j++)
            {
                if (list2[i] == list1[j])
                    ans.push_back(make_pair(i + j, list2[i]));
            }
        }
        sort(ans.begin(), ans.end());
        vector<string> res;
        int asize = ans.size(), flag = ans[0].first;
        for (int i = 0; i < asize; i++)
        {
            if (ans[i].first == flag)
                res.push_back(ans[i].second);
        }
        return res;
    }
};