

public class Main
{
    public static int fact(int n) {
        int ret = 1;
        for(int i=2; i<=n; i++) ret *= i;
        return ret;
    }

    public static String perm(int num, boolean[] flags, int count) {
        if(count == 0) return "";
        int f = fact(count - 1);
        int next = num / f;
        int nextNum = num - next * f;
        String ret = "";
        for(int i=0; i<flags.length; i++) {
            if(flags[i] && next == 0) {
                flags[i] = false;
                ret += i;
                break;
            } else if(flags[i]) {
                next--;
            }
        }
        return ret + perm(nextNum, flags, count-1);
    }

    public static void main(String[] args) {
        boolean[] flags = new boolean[10];
        for(int i=0; i<10; i++) flags[i] = true;
        System.out.println(perm(999999, flags, 10));
    }

}
