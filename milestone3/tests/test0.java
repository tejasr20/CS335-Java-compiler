// public class test0 {
//     // public static int factorial(int n) {
//     //     return n == 0 ? 1 : n * factorial(n - 1);
//     // }

//     public static void main(String[] args) {
//         int n=4;
// 		// n=4;
// 		// // n[2]= 3;
// 		int arr[]= new int[n];
// 		arr[n-1]= 5;
// 		// int c= 2;
// 		// c= n;
// 		// n= arr[2];
// 		// int arr2[][]= new int[3][7];
// 		// arr2[2][3]= n;
// 		// n= arr2[1][7];
// 		int arr3[][][][]= new int[3][7][10][4];
// 		arr3[2][1][4][1]= n;
// 		/*
// 		 t1= 2* 7* 4
// 		 t2= 3* 4
// 		 t3= t1+ t2
// 		 t4= arr[t3]
// 		 t4= 7
// 		 */

// 		// if(n<7)
// 		// {
// 		// 	n=6;
// 		// }
// 		// int x;
// 		// {
// 		// 	int c;
// 		// 	{
// 		// 		long f;
// 		// 	}
// 		// }
//         // int result = factorial(n);
//         // System.out.println(result);
//     }
    
// }

public class test0 {
	int x;
    double y;

	test0(int x, double y) {
		this.x = x;
		this.y = y;
	}
    public static void main(String[] args /*so that we can compile with javac*/) {
    	test0 a = new test0(2,3.14);
        System.out.println(a.x);
        System.out.println(a.y);
    }
}
