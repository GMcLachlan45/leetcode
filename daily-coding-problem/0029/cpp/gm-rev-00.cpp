#include <iostream>
#include <string>

std::string runlengthEncode(std::string str) {
    if(!str.size())
        return "";
    std::string encoded = "";
    int count = 1;
    for(int i = 1; i < str.size(); i++) {
        if(str[i] != str[i-1]) {
            encoded +=  std::to_string(count) + str[i-1];
            count = 0;
        }
        count++;
    }
    encoded += std::to_string(count) + str[str.size() - 1];
    return encoded;
}

std::string runlengthDecode(std::string str) {
    if(!str.size())
        return "";
    std::string decoded = "";
    int num_start = 0;
    for(int i = 1; i < str.size(); i++) {
        if(!(str[i] >= '0' && str[i] <='9')) {
            decoded += std::string(std::stoi(str.substr(num_start)), str[i]);
            num_start = i+1;
        }
    }
    return decoded;
}

int main() {
    std::string input = "AAAABBBCCDAA";
    std::cout << "For the string " << input << std::endl;
    std::string encoded = runlengthEncode(input);
    std::cout << "we have the encoding " << encoded<<std::endl;;
    std::string decoded = runlengthDecode(encoded);
    std::cout << "which after decoding is " << decoded<<std::endl<<std::endl;

    input = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    std::cout << "For the string " << input << std::endl;
    encoded = runlengthEncode(input);
    std::cout << "we have the encoding " << encoded<<std::endl;;
    decoded = runlengthDecode(encoded);
    std::cout << "which after decoding is " << decoded<<std::endl <<std::endl;

    input = "";
    std::cout << "For the string " << input << std::endl;
    encoded = runlengthEncode(input);
    std::cout << "we have the encoding " << encoded<<std::endl;
    decoded = runlengthDecode(encoded);
    std::cout << "which after decoding is " << decoded<<std::endl;

}
