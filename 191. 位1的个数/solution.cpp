class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n > 0) {
            count += (n & 0x1);
            n = n >> 1;
        }
        return count;
    }

    int hammingWeight1(uint32_t n) {
        int count = 0;
        while (n > 0) {
            n &= n - 1;
            ++count;
        }
        return count;
    }
};