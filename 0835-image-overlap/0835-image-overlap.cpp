class Solution {
public:
    int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
{
    int n = img1.size();
    vector<pair<int, int>> vec_a, vec_b;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (img1[i][j] == 1)
            {
                vec_a.push_back({i, j});
            }
            if (img2[i][j] == 1)
            {
                vec_b.push_back({i, j});
            }
        }
    }
    int ans = 0;
    map<pair<int, int>, int> mp;
	// it stores the displacement of 1 in img1 and 1 in img2  

    for (auto i : vec_a)
    {
        for (auto j : vec_b)
        {
            mp[{i.first - j.first, i.second - j.second}]++;
            ans = max(ans, mp[{i.first - j.first, i.second - j.second}]);
        }
    }
    
    return ans;
}
};