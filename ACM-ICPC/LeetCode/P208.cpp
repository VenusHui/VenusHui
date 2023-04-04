// 208. 实现 Trie (前缀树)
class Trie {
private:
    const int maxn = 26;
    vector<pair<vector<int>, int>> trie;
public:
    Trie() {
        trie = vector<pair<vector<int>, int>>(1, make_pair(vector<int>(maxn), 0));
    }
    
    void insert(string word) {
        int pos = 0;
        for (auto& e : word) {
            if (!trie[pos].first[e - 'a']) {
                trie[pos].first[e - 'a'] = trie.size();
                trie.push_back(make_pair(vector<int>(maxn), 0));
            }
            pos = trie[pos].first[e - 'a'];
        }
        trie[pos].second++;
    }
    
    bool search(string word) {
        int pos = 0;
        for (auto& e : word) {
            if (!trie[pos].first[e - 'a']) return false;
            pos = trie[pos].first[e - 'a'];
        }
        return trie[pos].second > 0;
    }
    
    bool startsWith(string prefix) {
        int pos = 0;
        for (auto& e : prefix) {
            if (!trie[pos].first[e - 'a']) return false;
            pos = trie[pos].first[e - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */