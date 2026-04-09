class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>res;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=1;i<=n;i++){
            mp[i]++;
        }
        for(int i : nums){
            mp[i]++;
        }
        for(auto &p:mp){
            if(p.second==3){
                res.push_back(p.first);
                break;
            }
            
        }

        for(auto &p:mp){
            if(p.second==1){
                res.push_back(p.first);
                break;
            }
        }

        return res;
    }
};