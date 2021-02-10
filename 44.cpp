class Solution {
public:
    int findNthDigit(int n) {
        if (n<10) {
            return n;
        }
        long long digitsSum = 9;
        long long sum = 9;
        int i = 2;
        long long increase; 
        while(true) {
            increase = 9 * pow(10, i-1);
            if (n <= digitsSum + i * increase) {
                break;
            }
            digitsSum += i * increase;
            sum += increase;
            i++;
        }
        int diff = n - digitsSum;
        sum += ((diff+(i-1))/i);
        int no = (diff-1) % i;
        return (int)(sum / pow(10, i-1-no)) % 10;
    }
};