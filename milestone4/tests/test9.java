public class test9 {
  int x;
  double y;

  test9(int x, double y) {
  		this.x = x;
      this.y = y;
  }

  public static void main(String[] args /*so that we can compile with javac*/) {
  		test9 a = new test9(2,3.14);
      System.out.println(a.x);
      System.out.println(a.y);
  }
}