import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        var scanner = new Scanner(System.in);
        var input = scanner.nextLine();

        String[] splited = input.split("\\s+");

        var fizz = Integer.parseInt(splited[0]);
        var buzz = Integer.parseInt(splited[1]);
        var end = Integer.parseInt(splited[2]);

        for (var i=0; i < end; i++){
            boolean fizzFlag = false;
            boolean buzzFlag = false;

            if ((i+1) % fizz == 0) {
                fizzFlag = true;
            }
            if ((i+1) % buzz == 0) {
                buzzFlag = true;
            }
            if (fizzFlag && buzzFlag) {
                System.out.println("FizzBuzz");
            } else if (fizzFlag) {
                System.out.println("Fizz");
            } else if (buzzFlag) {
                System.out.println("Buzz");
            } else {
                System.out.println(i+1);
            }
        }
    }
}