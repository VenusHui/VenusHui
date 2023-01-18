// 2526. 找到数据流中的连续整数
class DataStream {
private:
    int value = 0;
    int k = 0;
    int flag = 0;
public:
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
    }
    
    bool consec(int num) {
        if (num == value) {
            flag++;
        }
        else {
            flag = 0;
        }
        return flag >= k;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */