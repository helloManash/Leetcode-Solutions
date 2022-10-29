class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>m;   //key: number & value: streak length
        
        for(int i = 0; i < nums.size(); i++){
            int no = nums[i];
            
            if(m.count(no)){
                continue;
            }
            if(m.count(no - 1) == 0 && m.count(no + 1) == 0){
                m[no] = 1;
            }
            else if(m.count(no - 1) && m.count(no + 1)){
                int length1 = m[no - 1];
                int length2 = m[no + 1];
                
                int total_streak = length1 + 1 + length2;
                m[no - length1] = total_streak;
                m[no + length2] = total_streak;
                m[no] = 1;
            }
            else if(m.count(no - 1) && !m.count(no + 1)){
                m[no] = m[no - 1] + 1;
                m[no - m[no - 1]] = m[no];
            }
            else{
                int length = m[no + 1];
                m[no + length] = length + 1;
                m[no] = length + 1;
            }
            
        }
        int largest = 0;
        for(auto pr: m){
            largest = max(largest, pr.second);
        }
        return largest;
    }
};