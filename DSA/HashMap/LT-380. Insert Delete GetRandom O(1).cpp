class RandomizedSet {
private:
unordered_map<int,int> map;
vector<int> arr;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(map.find(val)!=map.end()){
            return false;
        }
        map[val]=arr.size();
        arr.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(map.find(val)==map.end()){
            return false;
        }
        int idx=map[val];
        map[arr.back()]=idx;
        map.erase(val);
        arr[idx]=arr.back();
        arr.pop_back();
        return true;
    }
    
    int getRandom() {
        int idx= rand() % arr.size();
        return arr[idx];
    }
};
