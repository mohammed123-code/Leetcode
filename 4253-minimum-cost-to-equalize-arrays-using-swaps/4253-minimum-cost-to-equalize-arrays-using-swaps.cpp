class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {

        int n=nums1.size();
        if(nums1.size()!=nums2.size()){
            return -1;
        }
        unordered_map<int,int>f1,f2;


        for(int x:nums1){
            f1[x]++;
        }

        for(int x:nums2){
            f2[x]++;
        }

        int count=0;

        unordered_set<int>keys;

        for(auto  &p:f1){
            keys.insert(p.first);
        }

        for(auto  &p:f2){
            keys.insert(p.first);
        }
        
        for(int v:keys){
            int diff=f1[v]-f2[v];

            if(diff%2!=0){
                return -1;
            }

            if(diff>0){
                count+=diff;
            }
        }
        return count/2;
    }
};