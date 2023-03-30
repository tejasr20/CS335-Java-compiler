import java.util.Scanner;
import java.util.Scanner;
import java.util.Scanner;
import java.util.*;

public class GradeChecker {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter your grade: ");
        int grade = scanner.nextInt();
        
        String message = "Your grade is ";
        if (grade >= 90) {
            message += "A";
        } else if (grade >= 80) {
            message += "B";
        } else if (grade >= 70) {
            message += "C";
        } else if (grade >= 60) {
            message += "D";
        } else {
            message += "F";
        }
        System.out.println(message);
    }
}
