public class test1 {
    public static int factorial(int n) {
        return n == 0 ? 1 : n * factorial(n - 1);
    }

    public static void main(String[] args) {
        int n = 5;
        int result = factorial(n);
        System.out.println(result);
    }
    
}
