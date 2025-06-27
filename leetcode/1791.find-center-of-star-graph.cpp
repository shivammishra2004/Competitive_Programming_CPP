/*
 * @lc app=leetcode id=1791 lang=cpp
 *
 * [1791] Find Center of Star Graph
 */

// @lc code=start
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> mpp;
        for(int i=0;i<edges.size();i++){
            mpp[edges[i][1]]++;
            mpp[edges[i][0]]++;
            if(mpp[edges[i][1]] == 2) return edges[i][1];
            else if(mpp[edges[i][0]] == 2) return edges[i][0];
        }
    }
};
// @lc code=end

