class NumberContainers {
public:
    map<int,set<int>>mp1;
    map<int,int>mp2;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(mp2.count(index)){
            if(mp2[index] != number){
                
                auto it = mp1[mp2[index]].find(index);
                mp1[mp2[index]].erase(it);
                
            }
        }
        mp1[number].insert(index);
        mp2[index] = number;
    }
    
    int find(int number) {
        if(!mp1[number].empty()){
            auto it = mp1[number].begin();
            
            return *it;
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */