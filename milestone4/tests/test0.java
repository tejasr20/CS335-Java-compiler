public class test0 {
    // public static int factorial(int n) {
    //     return n == 0 ? 1 : n * factorial(n - 1);
    // }
	int a;
	int b;
	// static int max(int a, int b)
	// {
	// 	int c=2;
	// 	a= c;
	// 	c= b*a + b/2;
	// 	// c= a+b+c;
	// 	// return a>b?a:b;
	// 	return 1;
	// }
	public static int fun(){return 1;}
	// public  int min(int a, int b)
	// {
	// 	return a<b?a:b;
	// }
	test0(int a1, int b1)
	{
		this.a= a1;
		this.b= b1;
	}

	test0()
	{
		this.a= 4;
		this.b= 5;
	}

    public static void main(String[] args) {
        // int n=4;
		// // // n=4;
		// // // // n[2]= 3;
		// n= max(5, 4);
		test0 obj = new test0(1,2);
		test0 obj1 = new test0();
		// test0 obj = new test0();
		obj.b= 4;
		// fun();
		int n = obj.fun();

		// System.out.println(obj.a);
		// 
		// n= obj.min(2,3);
		// int arr[]= new int[3];
		// arr[2]= 5;
		// int c= 2;
		// c= n;
		// n= arr[2];
		// int arr2[][]= new int[3][7];
		// arr2[2][3]= n;
		// int arr3[][][][]= new int[3][7][10][4];
		// arr3[2][1][4][1]= n;
		/*
		 t1= 2* 7* 4
		 t2= 3* 4
		 t3= t1+ t2
		 t4= arr[t3]
		 t4= 7
		 */

		// if(n<7)
		// {
		// 	n=6;
		// }
		// int x;
		// {
		// 	int c;
		// 	{
		// 		long f;
		// 	}
		// }
        // int result = factorial(n);
        // System.out.println(result);
    }
    
}
