class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }

        //minimum length string in the given strs
        int mini=INT_MAX;
        for(string s:strs){
            if(s.size()<mini){
                mini=s.size();
            }
        }

        //comparing..
        for(int i=0;i<mini;i++){
            char ch=strs[0][i];    //there is only one row, and we are iterating oevr columns, so [0][i]
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]!=ch){
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0].substr(0,mini);
    }
};