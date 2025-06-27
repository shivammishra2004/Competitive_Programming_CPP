/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& s) {
            int i = 0,j=0;
    int maxi = 0,k= 2;
    unordered_map<int,int> mpp;
    int count = 0;
    while(j<s.size()){
        mpp[s[j]]++;
        if(mpp[s[j]] == 1)count++;
        while(count>k){
            mpp[s[i]]--;
            if( mpp[s[i]]== 0)count--;
            i++;
        }
        if(count<=k)maxi = max(maxi,j-i+1);
        j++;
    }
    return maxi;
    }
};
// @lc code=end

