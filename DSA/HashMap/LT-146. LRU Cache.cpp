class LRUCache {
public:
    int cap;
    unordered_map<int,list<pair<int,int>>::iterator> map;
    list<pair<int,int>> dll;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        auto it=map.find(key);
        if(it==map.end()){
            return -1;
        }
        auto kv=it->second;
        pair<int,int> newVal=*kv;
        dll.erase(kv);
        //map.erase(it);
        dll.push_front(newVal);
        map[key]=dll.begin();
        return newVal.second;
    }
    
    void put(int key, int value) {
        auto it=map.find(key);
        if(it!=map.end()){
            dll.erase(it->second);
            //map.erase(it);
            dll.push_front({key,value});
            map[key]=dll.begin();
        }else{
            if(cap==(int)dll.size()){
                auto last=dll.back();
                dll.pop_back();
                map.erase(last.first);
            }
            dll.push_front({key,value});
            map[key]=dll.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
