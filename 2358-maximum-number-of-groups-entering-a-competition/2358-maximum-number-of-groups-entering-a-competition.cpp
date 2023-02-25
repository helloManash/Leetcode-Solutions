class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int cnt = 1;
        sort(grades.begin(), grades.end());
        int n = grades.size();
        int temp = 0;
        for(int i = 1; i <= n; i++){
            if(cnt > n - i){
                temp = n - i;
                break;
            }
            else{
                i += cnt - 1;
                cnt++;
            }
        }
        return (temp + 1 != cnt) ? cnt - 1: cnt;
    }
};