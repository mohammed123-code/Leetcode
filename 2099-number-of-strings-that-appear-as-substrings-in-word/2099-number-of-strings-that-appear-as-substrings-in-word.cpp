class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count=0;
        for(string sub : patterns){
            if(word.find(sub) != string::npos){
                count++;
            }
        }
        return count;
    }
};