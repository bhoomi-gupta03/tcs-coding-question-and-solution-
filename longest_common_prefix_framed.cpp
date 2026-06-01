/*
LEETCODE 14 : LONGEST COMMON PREFIX

Problem:
Given an array of strings strs, find the longest common prefix
among all strings. If no common prefix exists, return "".

Example:
Input: [\"flower\",\"flow\",\"flight\"]
Output: \"fl\"
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for(int i = 1; i < strs.size(); i++) {
            while(strs[i].find(prefix) != 0) {
                prefix.pop_back();
                if(prefix.empty()) return "";
            }
        }
        return prefix;
    }
};

int main() {
    Solution obj;
    vector<string> strs = {"flower","flow","flight"};
    cout << obj.longestCommonPrefix(strs);
    return 0;
}
