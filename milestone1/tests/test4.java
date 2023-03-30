public class Person {
    private String name;
    private int age;
    
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
    
    public String getName() {
        return this.name;
    }
    
    public int getAge() {
        return this.age;
    }
    
    public void setName(String name) {
        this.name = name;
    }
    
    public void setAge(int age) {
        this.age = age;
    }
    
    public static void main(String[] args) {
        Person person1 = new Person("John", 30);
        System.out.println("Person 1: " + person1.getName() + ", " + person1.getAge());
        
        Person person2 = new Person("Jane", 25);
        System.out.println("Person 2: " + person2.getName() + ", " + person2.getAge());
        
        person1.setAge(31);
        System.out.println("Person 1: " + person1.getName() + ", " + person1.getAge());
    }
}
