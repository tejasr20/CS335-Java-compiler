// Java program to find GCD of two numbers
class GFG {
    // Gcd of x and y using recursive function
    static int GCD(int x, int y)
    {
        // Everything is divisible by 0
        if (x == 0)
            return y;
        if (y == 0)
            return x;
  
        // Both the numbers are equal
        if (x == y)
            return x;
  
        // x is greater
        if (x > y)
            return GCD(x - y, y);
        return GCD(x, y - x);
    }
  
    // The Driver method
    public static void main(String[] args)
    {
		int rows = 4;
        int columns = 4;
 
        int arr[][] = new int[rows][columns];
	
        int value = 1;
    
 
        System.out.println("The 2D arr is: ");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                System.out.println(arr[i][j] + " ");
            }
            System.out.println("\n");
        }
        int x = 100, y = 88;
        System.out.println("GCD of " + x + " and " + y
                           + " is " + GCD(x, y));
    }
}