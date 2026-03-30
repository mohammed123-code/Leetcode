class EventManager {
public:

    priority_queue<pair<int,int>>pq;
    unordered_map<int,int>mp;
    EventManager(vector<vector<int>>& events) {
        for(auto &e : events){
            int id=e[0],priority=e[1];
            mp[id]=priority;
            pq.push({priority,-id});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        mp[eventId] = newPriority;
        pq.push({newPriority,-eventId});
        
    }
    
    int pollHighest() {
        while(!pq.empty()){
            auto[priority,negld]=pq.top();
            int id=-negld;

            if(mp.count(id)&&mp[id]==priority){
                pq.pop();
                mp.erase(id);
                return id;
            }
            pq.pop();
        }
        return -1;
        
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */