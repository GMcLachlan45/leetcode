// Runtime: 19ms
// Memory: 34.4MB
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ret = 0;
        if(minutes >= customers.size()) {
            for(int x : customers)
                ret += x;
            return ret;
        }

        int satisfiedCustomers = 0;
        int dissatisfiedCustomers = 0;
        for(int i = 0; i < minutes; i++) {

            if (grumpy[i])
                dissatisfiedCustomers += customers[i];
            else
                satisfiedCustomers += customers[i];

        }
        int maxDissatisfiedCustomers = dissatisfiedCustomers;

        for(int i = minutes; i < customers.size(); i++) {
            if(grumpy[i])
                dissatisfiedCustomers += customers[i];
            else
                satisfiedCustomers += customers[i];
            if(grumpy[i - minutes])
                dissatisfiedCustomers -= customers[i - minutes];
            if(dissatisfiedCustomers > maxDissatisfiedCustomers)
                maxDissatisfiedCustomers = dissatisfiedCustomers;
        }
        return satisfiedCustomers + maxDissatisfiedCustomers;
    }
};
