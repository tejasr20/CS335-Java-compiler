public class recursion {
    public static void main(String[] args) {
        int num = 5;
        int factorial = factorial(num);
        System.out.println("The factorial of " + num + " is " + factorial + ".");
    }

    public static int factorial(int n) {
        if (n == 0 || n == 1) {
            return 1;
        } else {
            return n * factorial(n - 1);
        }
    }
}

