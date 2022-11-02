class Solution {
    public int getSum(int a, int b) {
        while(b!=0){
            int temp=(a & b) << 1;     //AND operation
            a=(a ^ b);       //XOR
            b=temp;
        }
        return a;
    }
}