class StreamChecker {
private:
    const int maxn = 26;
    vector<pair<vector<int>, int>> trie;
    function<void(string)> insert = [&] (string s) {
        int pos = 0;
        for (auto& e : s) {
            if (trie[pos].first[e - 'a'] == 0) {
                trie[pos].first[e - 'a'] = trie.size();
                trie.push_back(make_pair(vector<int>(maxn), 0));
            }
            pos = trie[pos].first[e - 'a'];
        }
        trie[pos].second++;
    };
    const int maxlen = 200;
    string s;
public:
    StreamChecker(vector<string>& words) {
        trie = vector<pair<vector<int>, int>>(1, make_pair(vector<int>(maxn), 0));
        for (auto& e : words) {
            reverse(e.begin(), e.end());
            insert(e);
        }
    }
    
    bool query(char letter) {
        s += letter;
        int size = s.size();
        int minn = max(0, size - maxlen), pos = 0;
        for (int i = size - 1; i >= minn; i--) {
            if (trie[pos].second) return true;
            if (!trie[pos].first[s[i] - 'a']) return false;
            pos = trie[pos].first[s[i] - 'a'];
        }
        return trie[pos].second > 0;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */