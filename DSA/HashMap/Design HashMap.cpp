// 1. Insert: Add or update a (key, value) pair.
// 2. Get: Print the value for a given key, or -1 if the key doesn't exist.
// 3. Delete: Remove a key and its corresponding value if present.
// Sample Testcase 0
// Testcase Input
// 8
// 1 1 1
// 1 2 2
// 2 1
// 2 3
// 1 2 1
// 2 2
// 3 2
// 2 2
// Testcase Output
// 1
// -1
// 1
// -1
// Explanation
// For query 1, we insert (1, 1). Our map is now [(1, 1)]
// For query 2, we insert (2, 2). Our map is now [(1, 1), (2, 2)]
// For query 3, we print value corresponding to key 1, i.e., 1
// For query 4, we do not have the key 3 in our map, hence we print -1
// For query 5, we update the value corresponding to key 2 to 1. Out map now is [(1, 1), (2, 1)]
// For query 6, we print the value corresponding to key 2, i.e., 1
// For query 7, we delete the key 2 from the map. Out map now is [(1, 1)]
// For query 8. we do not have the key 2 in our map anymore, hence we print -1

#include <iostream>
#include <vector>
#include <tuple>
#include<list>

using namespace std;
class MyHashMap{
    private:
    static const int SIZE=100;
    vector<list<pair<int,int>>> bucket; //wehave used list to use collision chaining if same key occurs
    int hash(int key){
        return key%SIZE;
    }
    public:
    MyHashMap() {
    bucket.resize(SIZE);  
    }
    void put(int key,int val){
        int idx=hash(key);
        for(auto& pair:bucket[idx]){
            if(pair.first==key){
                pair.second=val;
                return ;
            }
        }
        bucket[idx].emplace_back(key,val);
    }
    int get(int key) {
        int idx = hash(key);
        for (const auto& pair : bucket[idx]) {
            if (pair.first == key)
                return pair.second;
        }
        return -1; // Not found
    }
    void remove(int key) {
        int idx = hash(key);
        auto& buckets = bucket[idx];
        for (auto it = buckets.begin(); it != buckets.end(); ++it) {
            if (it->first == key) {
                buckets.erase(it);
                return;
            }
        }
    }
};
vector<int> processQueries(vector<tuple<int, int, int>> queries) {
    int n=queries.size();
    vector<int> res;
    MyHashMap map;
    for(int i=0;i<n;i++){
        int type, key, value; 
        tie(type,key,value)=queries[i];
        if(type==1){
            map.put(key,value);
        }else if(type==2){
            res.push_back(map.get(key));
        }
        else{
            map.remove(key);
        }
    }
    // Write your logic here.
    // Parameters:
    //     queries (list): List of tuples, where each tuple represents a query.
    //                     For type 1: (1, key, value)
    //                     For type 2: (2, key)
    //                     For type 3: (3, key)
    // Returns:
    //     list: List of results for type 2 queries.
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> queries;
    for (int i = 0; i < n; ++i) {
        int queryType;
        cin >> queryType;
        if (queryType == 1) {
            int key, value;
            cin >> key >> value;
            queries.emplace_back(1, key, value);
        } else if (queryType == 2) {
            int key;
            cin >> key;
            queries.emplace_back(2, key, 0);
        } else if (queryType == 3) {
            int key;
            cin >> key;
            queries.emplace_back(3, key, 0);
        }
    }
    vector<int> results = processQueries(queries);
    for (int result : results) {
        cout << result << endl;
    }
    return 0;
}
