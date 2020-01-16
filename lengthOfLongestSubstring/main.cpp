#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int charToInt(char a) {
        return int(a);
    }

    int lengthOfLongestSubstring(string s) {
        int maxLength(0), startLoc(0), curLength(0);
        int hashArray[128];
        memset(hashArray, -1, sizeof(int) * 128);
        for (int i = 0; i < s.size(); ++i) {
            if (hashArray[int(s[i])] >= startLoc) {
                int nextStartLoc = hashArray[int(s[i])] + 1;
                for (int j = startLoc; j < nextStartLoc; ++j) {
                    hashArray[int(s[j])] = -1;
                }
                startLoc = nextStartLoc;
            }
            hashArray[int(s[i])] = i;
            curLength = i - startLoc + 1;
            maxLength = max(curLength, maxLength);
        }
        return maxLength;
    }

    int lengthOfLongestSubstring1(string s) {
        int maxLength(0), curLength(0), startLoc(0);
        unordered_map<char, int> hashmap;
        for (int i = 0; i < s.size(); ++i) {
            if (hashmap.find(s[i]) != hashmap.end() && hashmap[s[i]] >= startLoc) {
                int nextStartLoc = hashmap[s[i]] + 1;
                for (int j = startLoc; j < nextStartLoc; ++j) {
                    hashmap[s[j]] = -1;
                }
                hashmap[s[i]] = i;
                startLoc = nextStartLoc;
            } else {
                hashmap[s[i]] = i;
            }
            curLength = i - startLoc + 1;
            maxLength = max(curLength, maxLength);
        }
        return maxLength;
    }
};

int main() {
    string targetString;
    cin >> targetString;
    Solution solution;
    cout << solution.lengthOfLongestSubstring(targetString);
    return 0;
}