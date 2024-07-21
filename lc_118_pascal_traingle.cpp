#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        ans.push_back({1});

        for(int i = 1; i < numRows; i++){
            vector<int> tmp;

            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i)
                    tmp.push_back(1);
                
                else
                    tmp.push_back(ans[i - 1][j - 1] + ans[i-1][j]);
            }
            ans.push_back(tmp);
        }

        return ans;
    }
};