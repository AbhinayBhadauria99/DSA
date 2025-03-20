class MyHashSet {
public:
    vector<bool> sett; //defined a public boolean array named sett 
    MyHashSet() {       
        sett.resize(1e6 + 1, false); // in the constructor ,explicitally set the size of array i.e 1e6
    }
    
    void add(int key) {
        sett[key]=true;
    }
    
    void remove(int key) {
        sett[key]=false;
    }
    
    bool contains(int key) {
        return sett[key];
    }
};


/**
 * Example Usage:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */