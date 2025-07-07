class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();

        sort(events.begin() , events.end());
        int count = 0; //result
        int day = events[0][0];
        int i = 0;

        priority_queue<int , vector<int> , greater<int>> minheap;

        while(!minheap.empty() || i < n){
            
            if(minheap.empty()) day = events[i][0];

            while(i < n && events[i][0] == day){
                minheap.push(events[i][1]);
                i++;
            }

            if(!minheap.empty()){
                minheap.pop();
                count++;
            }

            day++;

            while(!minheap.empty() && minheap.top() < day){
                minheap.pop();
            }
        }

    return count;
    }
};