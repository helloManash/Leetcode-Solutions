class Solution {
public:
    void reverseString(vector<char>& s) {
        int size = s.size() - 1;
        int startIdx = 0, endIdx = size;
        while(startIdx < endIdx){
            char temp = s[startIdx];
            s[startIdx] = s[endIdx];
            s[endIdx] = temp;
            startIdx++;
            endIdx--;
        }
    }
};