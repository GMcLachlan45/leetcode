// Runtime: 103ms
// Memory: 61.1MB
class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        std::unordered_set<std::string> pos(positive_feedback.begin(), positive_feedback.end());
        std::unordered_set<std::string> neg(negative_feedback.begin(), negative_feedback.end());

        std::vector<int> feedback(student_id.size());
        for(int i = 0; i < feedback.size(); i++) {
            std::stringstream ss(report[i]);
            std::string token;
            while(std::getline(ss, token, ' ')) {
                if(pos.contains(token))
                    feedback[i] += 3;
                else if(neg.contains(token))
                    feedback[i]--;
            }
        }

        std::vector<int> idx(student_id.size());
        std::iota(idx.begin(), idx.end(), 0);

        std::sort(idx.begin(), idx.end(), [&](auto l, auto r) {
            if(feedback[l] == feedback[r])
                return student_id[l] < student_id[r];
            return feedback[l] > feedback[r];
        });
        idx.resize(k);
        for(int i = 0; i < k; i++)
            idx[i] = student_id[idx[i]];
        return idx;
    }
};
