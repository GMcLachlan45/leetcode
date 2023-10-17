// Runtime 38ms
// Memory 32.1MB

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        std::vector<bool> visited(n, false);
        for(int i = 0; i < n; i++) {
            if(leftChild[i] != -1){
                if(visited[leftChild[i]])
                    return false;
                visited[leftChild[i]] = true;
            }
            if(rightChild[i]!= -1){
                if(visited[rightChild[i]])
                    return false;
                visited[rightChild[i]] = true;
            }
        }

        int root = -1;
        for(int i = 0; i< n; i++){
            if(!visited[i]){
                if(root == -1){
                    root = i;
                    visited[i] = true;
                } else {
                    return false;
                }
            }
        }
        if(root == -1)
            return false;

        // Now start at root and validate that we reach every node
        int count = 0;
        std::queue<int> q;

        q.push(root);
        while(!q.empty()){
            int next = q.front();
            if(!visited[next])
                return false;
            q.pop();

            visited[next] = false;
            count++;
            if(leftChild[next]!=-1){
                q.push(leftChild[next]);
            }
            if(rightChild[next]!=-1){
                q.push(rightChild[next]);
            }
        }

        return count == n;
    }
};
