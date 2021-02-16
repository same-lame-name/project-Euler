public class euler003 {
   public static void main(String args[]){
       final PrimeFactorization primeFactorization = new PrimeFactorization();
       System.out.println(primeFactorization.solve());
       return;
   } 
}

class PrimeFactorization implements EulerSolution {
    public String solve(){
        Long number = 600851475143L;
        for(Long primeFactor = 2L; primeFactor * primeFactor <= number; ++primeFactor){
            if(number % primeFactor > 0) continue;
            while((number % primeFactor == 0) && number != primeFactor){
                number /= primeFactor;
            }
        }

        return String.valueOf(number);
    }
}

interface EulerSolution {
    public String solve();
}