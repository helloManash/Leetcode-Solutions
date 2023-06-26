class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        long long cost = 0;
        int n = costs.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        int t1 = 0, t2 = n-1;
        for(;t1<c && t1 < n;t1++){
            pq.push({costs[t1], t1});
        }
        for(int i=0;i<c && t2 >= t1;i++, t2--){
            pq.push({costs[t2], t2});
        }
        int count = 0;
        while(t1 <= t2){
            cost += pq.top().first;
            if(pq.top().second < t1){
                pq.pop();
                pq.push({costs[t1], t1});
                t1++;
            }
            else{
                pq.pop();
                pq.push({costs[t2], t2});
                t2--;
            }
            count++;
            if(count == k)break;
        }
        while(count < k){
            cost += pq.top().first;
            pq.pop();
            count++;
        }
        return cost;
    }
};
