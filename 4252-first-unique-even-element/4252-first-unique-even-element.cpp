class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int x : nums){
            if(x%2==0){
                mp[x]++;
            }
        }

        vector<int>res;
        for(int x:nums){
            if(x%2==0 && mp[x]==1){
                return x;
            }
        }
        return -1;
    }
};