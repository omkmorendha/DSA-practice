#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.second != b.second)
            return a.second < b.second;
        return a.first > b.first;
    }

    vector<int> frequencySort(vector<int> &nums)
    {
        unordered_map<int, int> umap;

        for (int i : nums)
            umap[i]++;

        vector<pair<int, int>> mapcopy(umap.begin(), umap.end());
        sort(mapcopy.begin(), mapcopy.end(), cmp);
        vector<int> ans;

        for (auto p : mapcopy)
        {
            ans.insert(ans.end(), p.second, p.first);
        }

        return ans;
    }
};