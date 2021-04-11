class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (Set.find(val) == Set.end()){
            elements.push_back(val);
            Set[val] = elements.size()-1;
            return true;
        }
        
        return false;
            
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
       if (Set.find(val) != Set.end()){
            auto it = Set.find(val);
        elements[it->second] = elements.back();
        elements.pop_back();
        
        Set[elements[it->second]] = it->second;
        Set.erase(val);
           
           return true;
        }
        
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int rand_idx = rand() % elements.size();
        
        return elements[rand_idx];
    }
private:
    unordered_map<int, int> Set;
    vector<int> elements;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */