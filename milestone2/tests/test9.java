public class test9
{
  private String fname;
  private String lname;
  private int age;

  
  public String getFname()
  {
    return fname;
  }

  
  public String getLname()
  {
    return lname;
  }

  
  public int getAge()
  {
    return age;
  }

  
  public void setAge(int ageVal)
  {
    age = ageVal;
  }
  public static void main(String[] args){
    test9 person1 = new test9();
    person1.age=2;
    person1.setAge(41);
    System.out.println(person1.getAge());
  }

}