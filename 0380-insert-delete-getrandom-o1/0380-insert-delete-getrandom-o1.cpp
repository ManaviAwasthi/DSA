class RandomizedSet {
public:
    vector <int> res;
    unordered_map <int, int> mp;
    RandomizedSet() {
        
    } 
    bool search (int val){
        if (mp.find(val)!=mp.end()){
            return true;
        }
        return false;    
    }
    
    bool insert(int val) {
        if (search(val)){
            return false;
        }
        res.push_back(val);
        mp[val]=res.size()-1;
        return true;
    }
    bool remove(int val) {
        if (!search(val)){
            return false;
        }
        auto it= mp.find(val);
        res[it->second]=res.back();
        res.pop_back();
        mp[res[it->second]]= it->second;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return res[rand()%res.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */