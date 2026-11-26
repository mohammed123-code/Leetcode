class Solution {
public:
    bool canAliceWin(int n) {
        int stone=10;
        bool temp=false;
        while(n>=stone){
            n-=stone;
            stone--;
            temp=!temp;
        }
        return temp;
    }
};