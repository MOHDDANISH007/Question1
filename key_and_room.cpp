class Solution {
public:
    void bfs(int starting_index, vector<vector<int>>& rooms, vector<bool>& visted){
        queue<int> q;
        q.push(starting_index);
        while(!q.empty()){
            int current = q.front();
            cout << current << endl;
            q.pop();

            for(auto it : rooms[current]){
                if(visted[it] != true){
                    visted[it] = true;
                    q.push(it);
                }
            }
        }


        
    }
   bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visted(rooms.size(),false);
        visted[0] = true; // given condition first room is open....

        int starting_index = 0;
        bfs(starting_index, rooms, visted);

        for(auto it: visted){
            if(it == false){
                return false;
            }
        }
        return true;

    }
};
