class RandomizedSet {
public:
    vector <int> vi;
    unordered_map <int, int> mp;
    /** Initialize your data structure here. */
    RandomizedSet() {
        vi.push_back(-1110101);
    }
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp[val]) return 0;
        mp[val] = vi.size();
        vi.push_back(val);
        return 1;
    }
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        //swap the last element with the element you delete.
        if(!mp[val]) return 0;
        int x = mp[val];
        mp[vi[vi.size() - 1]] = x;
        swap(vi[vi.size() - 1], vi[x]);
        mp[vi[vi.size() - 1]] = 0;
        vi.pop_back();
        return 1;
    }
    /** Get a random element from the set. */
    int getRandom() {
        int r = rand() % (vi.size() - 1) + 1;
        return vi[r];
    }
};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */