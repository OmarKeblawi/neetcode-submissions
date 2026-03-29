class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        int i = 0;
        while(i<32){
            res = res<<1;
            res |= (n & 1);
            n=n>>1;
            i++;
        }
        return res;
    }
};
