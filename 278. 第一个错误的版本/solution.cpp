// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    bool isBadVersion(int version) {
        return false;
    }

    int firstBadVersion(int n) {
        int l = 0, r = n;

        while (l != r) {
            int mid = l + (r - l) / 2;
            
            if (isBadVersion(mid)) {
                r = mid;
            } else {
                if (isBadVersion(mid + 1)) {
                    return mid + 1;
                } else {
                    l = mid;
                }
            }
        }

        return 0;
    }
};