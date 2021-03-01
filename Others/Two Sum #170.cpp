class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {

    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        hash[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        if (value > 200000 || value < -200000)
            return false;
        
        for (auto x: hash)
        {
            auto sum = hash.find(value - x.first);
            if (hash.find(value - x.first) == hash.end())
                continue;
            
            if ((sum->first != x.first) || sum->second > 1)
                return true;
        }
        return false;
    }

private:
    unordered_map<int, int> hash;
    
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */