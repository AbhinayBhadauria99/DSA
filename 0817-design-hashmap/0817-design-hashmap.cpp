class MyHashMap {
public:
    unordered_map <int,int> mpp;
    MyHashMap() {}
    
    void put(int key, int value) {mpp[key] = (value == 0 ? INT_MAX : value);}
    int get(int key) {return mpp[key] == 0 ? -1 : mpp[key] == INT_MAX ? 0 : mpp[key];}
    void remove(int key) {mpp.erase(key);}
};