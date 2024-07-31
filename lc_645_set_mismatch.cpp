#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int xr = 0;

        for(int i = 0; i < nums.size(); i++)
            xr ^= (nums[i] ^ (i + 1));

        int lsb = xr & ~(xr - 1);

        int one = 0;
        int zero = 0;

        for(int i = 0; i < nums.size(); i++){
            if((nums[i] & lsb) == 0)
                zero ^= nums[i];
            else
                one ^= nums[i];

            if(((i + 1) & lsb) == 0)
                zero ^= i + 1;
            else
                one ^= i + 1;
        }   

        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == one) count++;
        }

        if (count >= 2)
            return {one, zero};
        else
            return {zero, one};
    }
};