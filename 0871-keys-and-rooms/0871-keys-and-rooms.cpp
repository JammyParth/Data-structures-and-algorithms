class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);

        queue<int> q;
        q.push(0);
        
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            visited[temp] = true;

            for(auto neighbour : rooms[temp]){
                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        for(int i = 0; i < visited.size(); i++){
            if(visited[i] == false){
                return false;
            }
        }
    
    return true;
    }
};