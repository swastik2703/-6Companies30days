#include<climits>
#include<vector>
using namespace std;
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0;
        int curr = 0;
        int n = nums.size()-1;
        int ans = INT_MIN;
        vector<int>f(nums.size(),0);
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            curr += (i*nums[i]);
        }
        f[0] = curr;
        ans = max(ans,f[0]);

        //bakki ko dekho
        for(int i=1; i<f.size(); i++){
            f[i] = f[i-1] + sum - (nums.size()*nums[n]);
            n--;
            ans = max(ans,f[i]);
        }
        return ans;

    }
};