// Runtime 0ms
// Memory 13.7MB
class NestedIterator {
    int ptr;
    std::vector<int> iter;

    void flatten(vector<NestedInteger> &nestedList) {
        for(NestedInteger n: nestedList) {
            if(n.isInteger())
                iter.push_back(n.getInteger());
            else
                flatten(n.getList());
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
        ptr = 0;
    }

    int next() {
        return iter[ptr++];
    }

    bool hasNext() {
        return ptr<iter.size();
    }
};
