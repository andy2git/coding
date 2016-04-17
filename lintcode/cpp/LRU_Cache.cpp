#include <list>
class LRUCache{
private:
    unordered_map<int, list<pair<int, int>>::iterator> map;
    list<pair<int, int>> data;
    int cap;
    int size;

    void update(int k, int v){
        auto it = map[k];
        
        data.erase(it);
        data.push_front({k, v});
        map[k] = data.begin();
    }
    
public:
    // @param capacity, an integer
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    
    // @return an integer
    int get(int key) {
        if(map.find(key) == map.end()) return -1;
        
        auto it = map[key];
        int value = it->second;
        update(key, value);
        return value;
    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    void set(int key, int value) {
        if(map.find(key) != map.end()){
            update(key, value);
        }else{
            if(size == cap){
                map.erase(data.back().first);
                data.pop_back();
            }else{
                size++;
            }

            data.push_front({key, value});
            map[key] = data.begin();
        }
    }
};
