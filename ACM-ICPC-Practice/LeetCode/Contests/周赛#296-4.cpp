// 2296. 设计一个文本编辑器
class TextEditor {
private:
    string s;
    int cursor;
public:
    TextEditor() {
        s = "";
        cursor = 0;
    }
    
    void addText(string text) {
        s.insert(cursor, text);
        cursor += text.size();
    }
    
    int deleteText(int k) {
        int del = max(0, cursor - k);
        int ans = cursor - del;
        s.erase(del, ans);
        cursor -= ans;
        return ans;
    }
    
    string cursorLeft(int k) {
        string ans;
        cursor -= k;
        cursor = max(cursor, 0);
        int left = max(0, cursor - 10);
        for (int i = left; i < cursor; i++) {
            ans += s[i];
        }
        return ans;
    }
    
    string cursorRight(int k) {
        string ans;
        cursor += k;
        cursor = min(cursor, (int)s.size());
        int left = max(0, cursor - 10);
        for (int i = left; i < cursor; i++) {
            ans += s[i];
        }
        return ans;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */