class LFUCache {
    int capacity,minFreq;
    unordered_map<int,pair<int,int>> keyvalfreq;//key:{val,freq}
    unordered_map<int,list<int>> freqlist; //freq:LL
    unordered_map<int,list<int>::iterator> keyiter;//key:#LL
public:
    LFUCache(int capacity) {
        this->capacity=capacity;
    }
    int get(int key) {
        if(keyvalfreq.find(key)==keyvalfreq.end()){
            return -1;
        }
        auto [val,freq]=keyvalfreq[key];

        freqlist[freq].erase(keyiter[key]);
        if(freqlist[freq].empty() && minFreq==freq){
            minFreq++;
        }

        freq++;
        keyvalfreq[key].second=freq;
        freqlist[freq].push_front(key);
        keyiter[key]=freqlist[freq].begin();
        return val; 
    }
    
    void put(int key, int value) {
        if(get(key)!=-1){
            keyvalfreq[key].first=value;
            return;
        }

        if((int)keyvalfreq.size()>=capacity){
            int evictkey=freqlist[minFreq].back();
            freqlist[minFreq].pop_back();
            keyiter.erase(evictkey);
            keyvalfreq.erase(evictkey);
        }

        keyvalfreq[key]={value,1};
        freqlist[1].push_front(key);
        keyiter[key]=freqlist[1].begin();
        minFreq=1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
