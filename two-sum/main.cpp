/*
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

思路：
    空间换时间都o(n)
    哈希表使得单个查找o(1)，用set会失去位置信息，于是用map<val,loc>
    但是因为重复的val会叠加，所以往从后前查找，读到一个时，查前面有没有出现互补数
        出现了输出位置，还有当前的遍历次序i
 。*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <iterator>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> result;
        unordered_map<int, int> hashmap;
        for (int i = 0; i < nums.size(); ++i) {
            unordered_map<int, int>::iterator complement_loc = hashmap.find(target - nums[i]);
            if (complement_loc != hashmap.end()) {
                result.push_back(complement_loc->second);
                result.push_back(i);
                break;
            } else {
                hashmap[nums[i]] = i;
            }
        }
        return result;
    }
};

int main() {
    vector<int> q, r;
    int len, temp, target;
    cin >> len;
    cin >> target;
    for (int i = 0; i < len; ++i) {
        cin >> temp;
        q.push_back(temp);
    }

    Solution solution;
    r = solution.twoSum(q, target);
    cout << "question is:" << endl;
    for (const auto &num : r) {
        cout << num << ' ';
    }
    return 0;
}