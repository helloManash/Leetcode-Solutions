class Solution {
public:
    string pushDominoes(string manash) {
        int n = manash.size();
        vector<int>arr(n, -1);
        int left = -1, right = -1;
        for(int i=n-1;i>=0;i--){
            if(manash[i] == 'L')left = i;
            else if(manash[i] == 'R')left= -1;
            if(left == -1)continue;
            arr[i] = (left-i);
        }
        for(int i=0;i<n;i++){
            if(manash[i] == 'L')right = -1;
            else if(manash[i] == 'R')right = i;
            if(right == -1)continue;
            if(arr[i] == i-right){
                arr[i] = -1;
            }
            else if(arr[i] > i-right){
                arr[i] = -2;
            }
            else if(arr[i] == -1){
                arr[i] = -2;
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i] == -2){
                manash[i] = 'R';
            }
            else if(arr[i] > -1){
                manash[i] = 'L';
            }
        }
        return manash;
    }
};