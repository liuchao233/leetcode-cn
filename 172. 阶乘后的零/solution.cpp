class Solution {
public:
    int countFive(int n) {
        int count = 0;
        
        while (n > 0) {
            if (n % 5 == 0) {
                ++count;
            } else {
                break;
            }
            n /= 5;
        }

        return count;
    }

    int trailingZeroes(int n) {
        int zeros = 0;

        while (n > 0) {
            zeros += countFive(n--);
        }

        return zeros;
    }
};

30 

5 10 15 20 25 
