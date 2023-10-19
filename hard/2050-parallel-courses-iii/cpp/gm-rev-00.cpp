// Runtime 425ms
// Memory 274.5MB
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        std::vector<std::vector<int>> prereqs(n+1);
        for(std::vector<int> relation: relations) {
            prereqs[relation[1]].push_back(relation[0]);
        }
        int retTime = 0; // Will be the max of all these
        std::vector<int> totalTimes(n+1,-1);

        for(int i = 1; i <=n; i++){
            std::stack<int> st;
            if(totalTimes[i] == -1){
                st.push(i);
            }
            while(!st.empty()){
                int check = st.top();
                bool pushedReq = false;
                int preMax = 0;
                for(int req: prereqs[check]){
                    if(totalTimes[req] == -1){
                        st.push(req);
                        pushedReq = true;
                    } else
                        preMax = std::max(preMax, totalTimes[req]);
                }
                if(!pushedReq){
                    totalTimes[check]= preMax + time[check-1];
                    retTime = std::max(retTime,totalTimes[check]);
                    st.pop();
                }
            }
        }
      return retTime;
    }
};
