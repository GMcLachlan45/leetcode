// Runtime: 3ms
// Memory: 12MB
class Solution {
    std::string ones[20] = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine", " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
    std::string tens[10] = {"", "", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};

    std::string chunkToWord(int chunk, std::string xillion) {
        if(chunk == 0)
            return "";
        std::string ans = "";
        if(chunk/100)
            ans += ones[chunk/100] + " Hundred";
        if(chunk/10%10 >1)
            ans += tens[chunk/10%10] + ones[chunk%10];
        else
            ans += ones[chunk %100];
        return ans + xillion;
    }

public:
    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        std::string answer =
            chunkToWord(num / 1000000000, " Billion")
            + chunkToWord(num / 1000000 % 1000, " Million")
            + chunkToWord(num / 1000 % 1000, " Thousand")
            + chunkToWord(num % 1000, "");

        return answer.substr(1, answer.size()-1);
    }
};
