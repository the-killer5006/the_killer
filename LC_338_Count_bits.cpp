/* LC_338_Count_bits_till_num */

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result (num + 1);
        result[0] = 0;
        for (int i = 1; i <= num; i++)
            result[i] = result[i >> 1]  + (i & 0x1);
        return result;
    }
};
