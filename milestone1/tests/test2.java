public class TypeCastingDemo {
    public static void main(String[] args) {
        int i = 10;
        double d = 20.5;
        
        // Using assignment operators
        i += 5;    // Equivalent to i = i + 5
        d -= 2.5;  // Equivalent to d = d - 2.5
        
        // Using type casting
        int result = i + (int) d;
        
        System.out.println("i = " + i);
        System.out.println("d = " + d);
        System.out.println("result = " + result);
    }
}
