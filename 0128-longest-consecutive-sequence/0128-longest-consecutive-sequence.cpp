class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        unordered_map<int,int>mp;
        for(int num : nums){
            mp[num]++;
        }
        int maxi=0;
        for(auto it: mp){
            if(mp.find(it.first-1)==mp.end()){
                int j=1;
                count=1;
                while(mp.find(it.first+j)!=mp.end()){
                    count++;
                    j++;
                }
                maxi=max(maxi,count);
            }
        }
        return maxi;
    }
};