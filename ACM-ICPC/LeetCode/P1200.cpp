class Solution {
public:
  vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
    int n = arr.size();
    sort(a.begin(), a.end());
    int minn = 0x3f3f3f3f;
    for (int i = 0; i < n - 1; i++) {
      int diff = arr[i + 1] - arr[i];
      minn = min(minn, diff);
    }
    vector<vector<int>> ans;
    for (int i = 0; i < n - 1; i++) {
      if (arr[i + 1] - arr[i] == minn) {
        ans.push_back({arr[i], arr[i + 1]});
      }
    }
    return ans;
  }
};
