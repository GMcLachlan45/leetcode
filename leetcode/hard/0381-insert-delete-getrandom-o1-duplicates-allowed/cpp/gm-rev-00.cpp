// Runtime: 167ms
// Memory: 112.7MB
class RandomizedCollection {
    std::vector<int> store;
    std::unordered_map<int, std::unordered_set<int>> bucket;
public:
    RandomizedCollection() {
    }

    bool insert(int val) {
        bool notPresent = bucket[val].empty();
        bucket[val].insert(store.size());
        store.push_back(val);
        return notPresent;
    }

    bool remove(int val) {
        if(bucket[val].empty())
            return false;

        if(val == store[store.size()-1]) {
            bucket[val].erase(store.size()-1);
        } else {
            int idx = *bucket[val].begin();
            store[idx] = store[store.size()-1];
            bucket[store[idx]].erase(store.size()-1);
            bucket[store[idx]].insert(idx);
            bucket[val].erase(idx);
        }

        store.pop_back();
        return true;
    }

    int getRandom() {
        return store[rand() % store.size()];
    }
};
