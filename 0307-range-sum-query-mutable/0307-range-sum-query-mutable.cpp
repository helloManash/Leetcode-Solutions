class NumArray {
public:
    vector<int>v;
    vector<int>arr;
    NumArray(vector<int>& nums) {
        int size = nums.size();
        v.resize(size + 1);
        fill(v.begin(), v.end(), 0);
        arr.resize(size);
        fill(arr.begin(), arr.end(),0);
        
        for(int i = 0; i < size; i++){
            
            update(i, nums[i]);
        }
        
    }
    
    
    
    void update(int index, int val) {
        int size = v.size();
        index++;
        int num = val - arr[index - 1];
        arr[index - 1] = val;
        while(index < size){
            
            v[index] += num ;
            index += (index & (-index));
        }
    }
    
    int query(int i){
        int sum = 0;
        i++;
        while(i > 0){
            sum += v[i];
            i -= (i & (-i));
        }
        return sum;
    }
    int sumRange(int left, int right) {
        return (query(right) - query(left-1) );
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */