public class test3 {
    public static int factorial(int n) {
        if (n == 0 || n == 1) {
            return 1;
        } else {
            return n * factorial(n - 1);
        }
    }
    public static void main(String[] args) {
        int num = 5;
		int x;
		x= 5+(3*num)/(num*7);
        int factorial = factorial(num);
        System.out.println(factorial);
    }
}

