// 2336. 无限集中的最小数字
class SmallestInfiniteSet {
private:
    int maxn = 2000;
    set<int> st;
public:
    SmallestInfiniteSet() {
        for (int i = 1; i <= maxn; i++) {
            st.insert(i);
        }
    }
    
    int popSmallest() {
        int ans = *st.begin();
        st.erase(st.begin());
        return ans;
    }
    
    void addBack(int num) {
        if (st.find(num) == st.end()) {
            st.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */