/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        if (guess(n) == 0) {
            return n;
        }
        
        int l = 1, r = n;
        while (l < r) {
            int mid = (r - l) / 2 + l;
            int ret = guess(mid);

            if (ret == 0) {
                return mid;
            } else if (ret == 1) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return 0;
    }
};