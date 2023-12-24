class RandomizedSet {
public:
    vector<int>a;
    map<int,int>mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val)){
            return false;
        }
        a.push_back(val);
        mp[val] = (int)a.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()){
            return false;
        }
        a[mp[val]] = a.back();
        a.pop_back();
        mp[a[mp[val]]] = mp[val]; 
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return a[rand() % ((int)a.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */