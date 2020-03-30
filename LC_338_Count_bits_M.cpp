/* LC_338_Count_bits_till_num */

/* Approach - 1
* Right shift by one bit and take decision on new upcoming LSB
*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result (num + 1, 0);
        for (int i = 1; i <= num; i++)
            result[i] = result[i >> 1]  + (i & 0x1);
        return result;
    }
};


/* Approach - 2
* Drop the lowest set bit and add 1
*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result (num + 1, 0);
        for (int i = 1; i <= num; i++)
            result[i] = result[i & (i - 1)]  + 1;
        return result;
    }
};

/* Approach - 3
* n bit number is having similar repetion patteren of (n - 1) bits
* being taken care by offset and reset offset once power of 2 is there
*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result (num + 1, 0);
        int power_of_two = 1, offset = 0;
        for (int i = 1, offset = 0; i <= num; i++, offset++) {
            if (i == power_of_two) {
                power_of_two <<= 1;
                offset = 0; /* reset the cycle */
            }
            result[i] = result[offset]  + 1;
        }    
        return result;
    }
};

