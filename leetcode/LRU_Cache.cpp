class LRUCache{
private:
    int size;
    int cap;
    unordered_map<int, list<pair<int, int>>::iterator> map;
    list<pair<int, int>> lst;
    
    void update(int key, int val){
        auto it = map[key];
        pair<int, int> t = {key, val};
        lst.erase(it);
        lst.push_front(t);
        map[key] = lst.begin();
    }
    
    void remove_least(){
        pair<int, int> t = lst.back();
        lst.pop_back();
        map.erase(t.first);
        size--;
    }
    
    void insert(int key, int val){
        lst.push_front({key, val});
        map[key] = lst.begin();
        size++;
    }
    
public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    
    int get(int key) {
        if(map.find(key) == map.end()) return -1;
        int val = map[key]->second;
        update(key, val);
        return val;
    }

    void set(int key, int value) {
        if(map.find(key) != map.end()){
            update(key, value);
        }else{
            if(size == cap){
                 remove_least();   
            }
            insert(key, value);
        }
    }
};
