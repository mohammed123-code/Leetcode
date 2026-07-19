class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string res="";
        string rem="";

        for(char ch : s){
            if(ch==y){
                res+=ch;
            }
        }

        for(char ch : s){
            if(ch !=x && ch!=y){
                rem+=ch;
            }
        }


        res+=rem;



        for(char ch : s){
            if(ch==x){
                res+=ch;
            }
        }


        return res;
    }
};