//1ms
//39.9MB
class Solution {
    public int power(int x){
        int y = x;
        int s = 0;
        while(y > 0){
            s = s + (y%10) * (y%10);
            y = y/10;
        }
        return s;
    }
    
    public boolean isHappy(int n) {
        int a = n;
        int b = n;
        while(a > 1){
            a = power(a);
            if(a == 1)
                return true;
            b = power(power(b));
            if(b == 1)
                return true;
            if(a == b)
                return false;
        }
        return true;
    }
}
