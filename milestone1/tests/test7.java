public class Methods {
    public static void main(String[] args) {
        // Calling a static method
        System.out.println("The result of adding 5 and 3 is: " + add(5, 3));
        
        // Creating an instance of the class
        Methods obj = new Methods();
        
        // Calling a non-static method on the instance
        System.out.println("The factorial of 5 is: " + obj.factorial(5));
    }
    
    // A static method that adds two numbers
    public static int add(int a, int b) {
        return a + b;
    }
    
    // A non-static method that calculates the factorial of a number
    public int factorial(int n) {
        if (n == 0 || n == 1) {
            return 1;
        } else {
            return n * factorial(n - 1);
        }
    }
}

