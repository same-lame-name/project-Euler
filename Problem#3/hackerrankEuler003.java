import java.util.Scanner;

public class hackerrankEuler003 {
   public static void main(String args[]){
       final PrimeFactorization primeFactorization = new PrimeFactorization();
       Scanner scanner = new Scanner(System.in);
       int testcases = scanner.nextInt();

       while(testcases-- > 0){
            Long N = scanner.nextLong();
            System.out.println(primeFactorization.solve(N));
       }

       scanner.close();
       return;
   } 
}

class PrimeFactorization implements EulerSolution{
    public String solve(Long N){
        Long number = N; 
        for(Long primeFactor = 2L; primeFactor * primeFactor <= number; ++primeFactor){
            if(number % primeFactor > 0) continue;
            while((number % primeFactor == 0) && number != primeFactor){
                number /= primeFactor;
            }
        }

        return String.valueOf(number);
    }
}

interface EulerSolution{
    public String solve(Long N);
}
