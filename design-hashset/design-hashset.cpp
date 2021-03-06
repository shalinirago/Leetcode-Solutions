class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        hash.resize(1e6);
    }
    
    int hash_val(int key){
        return key % 10^6;
    }
    
    void add(int key) {
        auto& ind_list = hash[hash_val(key)];
        
        for (auto x: ind_list)
        {
            if (x == key)
            {
                return;
            }
        }
        ind_list.push_back(key);
    }
    
    void remove(int key) {
        auto& ind_list = hash[hash_val(key)];
        
        for (auto x: ind_list)
        {
            if (x == key)
            {
                ind_list.remove(x);
                return;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        auto& ind_list = hash[hash_val(key)];
        
        for (auto x: ind_list)
        {
            if (x == key)
            {
                return true;
            }
        }
        
        return false;
    }
private:
    vector<list<int>> hash;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */