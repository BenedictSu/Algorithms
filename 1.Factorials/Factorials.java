import java.math.BigInteger;
import java.util.Scanner;

class Factorials {
    // init to 100 + 1 to avoid having to count from zero
    private static BigInteger[] factorials = new BigInteger[101];

    public static void preCompute() {
        // initialise the first value
        factorials[1] = BigInteger.ONE;

        // compute each factorial (from 2 to 100) using the previous value
        // mutiply by the new integer
        for (int i = 2; i < 101; i++) {
            BigInteger currentNum = BigInteger.valueOf(i); 
            factorials[i] = factorials[i - 1].multiply(currentNum);
        }
    }

    public static void main(String[] args) {
        preCompute();
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            int input = scanner.nextInt();
            System.out.println(factorials[input]);
        }
        scanner.close();
    }

}