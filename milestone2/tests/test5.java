public class test5
{
	
	public static void printOne() {
		System.out.println("Hello World");
	}

	public static void printTwo() {
		printOne();
		printOne();
	}

    public static void main(String[] args) {
		printOne();
		printOne();
		printTwo();
	}

}