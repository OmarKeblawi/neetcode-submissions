class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){
            int xor_ab = a^b;
            int carry = a&b;
            a = xor_ab;
            b = carry<<1;
        }
        return a;
    }
};
