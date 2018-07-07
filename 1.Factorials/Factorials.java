import java.util.Scanner;

class Factorials {
    public static void main(String[] args) {
        Scanner scanner = new Scanner (System.in);
        while (scanner.hasNext()) {
            int input = scanner.nextInt();
            System.out.println(input);
        }
        scanner.close();
    }

}