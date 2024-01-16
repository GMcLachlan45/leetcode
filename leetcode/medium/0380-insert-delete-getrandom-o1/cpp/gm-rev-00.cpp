// Runtime: 182ms
// Memory: 97.85MB
class RandomizedSet {
    std::unordered_map<int, int> idxToVal;
    std::unordered_map<int, int> valToIdx;
    int count;
public:
    RandomizedSet() {
        count = 1;
    }

    bool insert(int val) {
        if(valToIdx[val])
            return false;
        idxToVal[count] = val;
        valToIdx[val] = count++;
        return true;
    }

    bool remove(int val) {
        if(!valToIdx[val])
            return false;
        int idx = valToIdx[val];
        valToIdx[idxToVal[count-1]] = idx;
        idxToVal[idx] = idxToVal[count-1];
        valToIdx[val] = 0;
        idxToVal[count-1] = 0;
        count--;
        return true;
    }

    int getRandom() {
        int randIdx = std::rand() % (count - 1) + 1;
        return idxToVal[randIdx];
    }
};
