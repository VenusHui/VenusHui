// 2227. 加密解密字符串
class Encrypter {
private:
    vector<char> k;
    vector<string> v;
    vector<string> d;
    int ksize, vsize, dsize;
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        k = keys;
        v = values;
        d = dictionary;
        ksize = keys.size();
        vsize = values.size();
        dsize = dictionary.size();
    }
    
    string encrypt(string word1) {
        string ans;
        int size = word1.size();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < ksize; j++) {
                if (word1[i] == k[j]) {
                    ans += v[j];
                }
            }
        }
        return ans;
    }
    
    int decrypt(string word2) {
        int ans = 0, size = word2.size();
        for (int i = 0; i < dsize; i++) {
            if (d[i].size() != size / 2){
                continue;
            }
            bool flag = true;
            for (int j = 0; j < size / 2; j++) {
                string tmp;
                tmp += word2[j * 2];
                tmp += word2[j * 2 + 1];
                flag = false;
                for (int t = 0; t < vsize; t++) {
                    if (tmp == v[t] && k[t] == d[i][j]) {
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    break;
                }
            }
            if (flag) {
                ans++;
            }
        }
        return ans;
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */