public class BitwiseAndArray {
    public static void main(String[] args) {
        // Bitwise operators
		// int a[5]= new int[5];
        int a = 10; // 1010 in binary
        int b = 6; // 0110 in binary
        
        int c = a & b; // Bitwise AND
        int d = a | b; // Bitwise OR
        int e = a ^ b; // Bitwise XOR
        int f = ~a; // Bitwise NOT
        
        System.out.println("a & b = " + c); // Output: 2
        System.out.println("a | b = " + d); // Output: 14
        System.out.println("a ^ b = " + e); // Output: 12
        System.out.println("~a = " + f); // Output: -11
        
        // Arrays
        int[][] arr1 = new int[5][5]; // Declare an array of integers with length 5
        arr1[0] = 1; // Assign a value to the first element
        arr1[1] = 2; // Assign a value to the second element
        arr1[2] = 3; // Assign a value to the third element
        arr1[3] = 4; // Assign a value to the fourth element
        arr1[4] = 5; // Assign a value to the fifth element
        
        int[] arr2 = {1, 2, 3, 4, 5}; // Declare and initialize an array of integers
        
        for (int i = 0; i < arr1.length; i++) {
            System.out.print(arr1[i] + " "); // Output: 1 2 3 4 5
        }
        System.out.println();
        
        for (int i = 0; i < arr2.length; i++) {
            System.out.print(arr2[i] + " "); // Output: 1 2 3 4 5
        }
        System.out.println();
    }
}
