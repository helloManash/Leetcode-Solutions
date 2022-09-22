class Solution {
public:
    string reverseWords(string s) {
        int size = s.length();
        int count = 0;
        for(int startIndex = 0; startIndex <= size; startIndex++){
            if(s[startIndex] != '\0' && s[startIndex] != ' '){
                count++;
                continue;
            }
            int lastIndex = startIndex - 1;
            int firstIndex = startIndex - count;
            while(firstIndex < lastIndex){
                char temp = s[firstIndex];
                s[firstIndex] = s[lastIndex];
                s[lastIndex] = temp;
                firstIndex++;
                lastIndex--;
            }
            count = 0;
        }
        return s;
    }
};