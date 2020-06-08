class Solution {
public:
 bool isPowerOfTwo(int n) {
        int count = 0;
        if(n == 0) return false;
        while(n != 0) {
            if(n%2 != 0)
                ++count;
            if(count > 1)
                return false;
            n = n>>1;
        }
        return true;
    }

};
