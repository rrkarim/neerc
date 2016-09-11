class RandomizedCollection {
public:
    unordered_map <int, unordered_set<int>> mp;
    unordered_map <int, int> u;
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand(time(NULL));
    }
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        int size = u.size();
        u[size+1] = val;
        if(!mp[val].empty()) {
            mp[val].insert(size+1);
            return 0;
        }
        else {
            mp[val].insert(size+1);
            return 1;
        }
    }
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp[val].size() > 0) {
            unordered_set <int> d = mp[val];
            int x = *(d.begin());
            mp[val].erase(x);
            if(x == u.size()) {
                u.erase(x);
                return 1;
            }
            int key = u[u.size()];
            mp[key].erase(u.size());
            mp[key].insert(x); 
            u.erase(u.size());
            u.erase(x);
            u[x] = key;
            return 1;
        }
        else return 0;
    }
    /** Get a random element from the set. */
    int getRandom() {
        if(u.size() == 0) return -1;
        if(u.size() == 1) return u[1];
        int r = rand() % (u.size()) + 1;
        return u[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val)5
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */