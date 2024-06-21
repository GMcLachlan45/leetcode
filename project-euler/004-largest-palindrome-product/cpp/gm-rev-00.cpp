#include <iostream>
#include <string>

int findLargestSixDigitPalindrome() {
    for(int abc = 999; abc >=100; abc--) {
        int potential_palindrome = abc * 1000
            + abc / 100
            + abc / 10 % 10 * 10
            + abc % 10 * 100;
        for(int i = 999; i >=100; i--)
            if(potential_palindrome % i == 0
               && potential_palindrome/i >= 100
               && potential_palindrome/i < 1000)
                return potential_palindrome;
    }
    return -1;
}
int main() {
    int ans = findLargestSixDigitPalindrome();
    std::cout<< "The largest Palindromic number that's a product of two three digit numbers is: "<< ans<<std::endl;
    return 0;
}
