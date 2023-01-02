#include<vector>
using namespace std;
class Solution {
    void help(int i, int k, int sumTillNow, int n, vector<int> &subSet, vector<vector<int>>&ans){
        //base case 
        if(k < 0){  //negative
            return;
        }   
        
        if(sumTillNow == n){
            if(k == 0){
                ans.push_back(subSet);
            }
            return;
        }

        //since hmare pass number sirf 1-9 tk hai
        if(i == 10) return;


        //agar aap element ko pick kr rhe ho toh 
        /*
        sum change hoga
        subset change hoga
        recrusion i+1, k-1 tk hoga */

        sumTillNow += i;
        subSet.push_back(i);
        help(i+1,k-1,sumTillNow,n,subSet,ans);
        //backtrack or krna hoga next ke liye toh uper vali condition vapis minus ho jayegi
        sumTillNow -= i;
        subSet.pop_back();

        //agar ignore kr rhe ho
        /*
        subset same rhega
        ans mai koi change nhi hoga
        recursion i+1 se hoga*/

        help(i+1,k,sumTillNow,n,subSet,ans);
        
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> subSet;
        vector<vector<int>> ans;
        help(1,k,0,n,subSet,ans);
        return ans;
    }
};