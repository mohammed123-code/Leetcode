class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int res=0;
        unordered_map<char,int>mp;    //Stores thhe last occurence of the charcters's index position
        for(int right=0;right<s.size();right++){
            if(mp.find(s[right])!=mp.end() && mp[s[right]]>=left) {
                left=mp[s[right]] + 1;
            }
            mp[s[right]]=right;
            res=max(res,right-left+1);
        }
        return res;
    }
};