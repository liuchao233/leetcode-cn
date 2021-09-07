class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }

        if (x < 4) {
            return 1;
        }

        int l = 0, r = x;
        while (l < (r - 1)) {
            int mid = (r - l) / 2 + l;
            if (mid > 46340) {
                r = 46341;
                continue;
            }
            int calc = mid * mid;
            
            if (calc == x) {
                return mid;
            } else if (calc < x) {
                l = mid;
            } else {
                r = mid;
            }
        }
        
        return l;
    }
};