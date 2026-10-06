class Solution {
public:
    int minAddToMakeValid(string s) {
        int rem=0;
        int insert=0;
        for(char ch : s){
            if(ch=='('){
                rem++;
            }
            else{
                if(rem>0){
                    rem--;
                }
                else{
                    insert++;
                }
            }
        }
        return rem+insert;
    }
    
};