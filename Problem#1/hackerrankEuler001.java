import java.math.BigInteger;
import java.util.Scanner;

public class hackerrankEuler001 {
    public static void main(String[] args){
        final EulerSolution methodOfBruteForce = new MethodOfBruteForce();
        final EulerSolution methodOfInclusionExclusion = new MethodOfInclusionExclusion();
        Scanner scanner = new Scanner(System.in);
        int testcases = scanner.nextInt();
        while(testcases-- > 0){
            int N = scanner.nextInt();
            System.out.println(methodOfInclusionExclusion.solve(N));
        }

        scanner.close();
        return;
    }
}

class MethodOfBruteForce implements EulerSolution{
    public String solve(int N){
        Long sumOfMultiplesOf3Or5 = 0L;
        for(int number = 1; number < N; ++number){
            if(number % 3 == 0 || number % 5 == 0) sumOfMultiplesOf3Or5 += number;
        }

        return String.valueOf(sumOfMultiplesOf3Or5);
    }
}

class MethodOfInclusionExclusion implements EulerSolution{
    public String solve(int N){
        Long sumOfMultiplesOf3Or5 = sumOfMultiplesOf(N, 3) + sumOfMultiplesOf(N, 5) - sumOfMultiplesOf(N, LCMof(3, 5));

        return String.valueOf(sumOfMultiplesOf3Or5);
    }


    public Long sumOfMultiplesOf(int N, int number){
        Long m = Long.valueOf(N - 1) / number;

        return number * m * (m + 1) / 2;
    }

    public int LCMof(int M, int N){
        BigInteger wrapM = BigInteger.valueOf(M);
        BigInteger wrapN = BigInteger.valueOf(N);
        BigInteger wrapGcd = wrapM.gcd(wrapN);
        int gcd = wrapGcd.intValue();

        return M * N / gcd;
    }
}

interface EulerSolution{
    public String solve(int N);
}
