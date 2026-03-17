class Solution {
public:
    bool checkOnesSegment(string s) {
        int count=0;
        if(s[0]=='1'){
            count++;
        }
        for(int i=1;i<s.size();i++){
            if(s[i]=='0'){
                continue;
            }
            if(s[i-1]==s[i]){
                continue;
            }
            count++;
        }
        return count==1;
    }
};