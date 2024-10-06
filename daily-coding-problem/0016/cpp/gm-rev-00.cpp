#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

class LogBook {
    std::vector<std::string> logs;
    int end;
public:
    LogBook(int N) {
        if(N < 1)
            throw std::runtime_error("Log book must hold 1 or more logs");
        logs = std::vector<std::string>(N, "No log found!");
        end = 0;
    }

    void record(std::string order_id) {
        logs[end++] = order_id;
        end %= logs.size();
    }

    std::string get_last(int i) {
        if(i < 1 || i > logs.size())
            throw std::out_of_range("i must be in {1,...,N}");
        return logs[(end - i + logs.size()) % logs.size()];
    }
};

int main() {
    LogBook logs(10);
    std::cout << "Logbook with 10 values created."<<std::endl;
    logs.record("D7CX");
    logs.record("23CD");
    std::cout << "The last log is "<< logs.get_last(1)<<std::endl;
    std::cout << "The second last log is "<< logs.get_last(2)<<std::endl;
    std::cout << "There is no log before the two inserted as proven by: "<< logs.get_last(3)<<std::endl;
}
