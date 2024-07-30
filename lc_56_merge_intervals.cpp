#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> new_arr(intervals); 
        sort(new_arr.begin(), new_arr.end(), comp);

        int index = 0;

        for(int i = 1; i < intervals.size(); i++){
            if(new_arr[i][0] > new_arr[index][1]){
                index++;
                new_arr[index] = new_arr[i];
            }
            else{
                new_arr[index][1] = max(new_arr[index][1], new_arr[i][1]);
            }
        }

        new_arr.resize(index + 1);
        return new_arr;
    }
};