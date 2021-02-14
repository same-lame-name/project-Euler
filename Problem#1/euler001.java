import java.math.BigInteger;

public class euler001 {
    public static void main(String[] args){
        final EulerSolution methodOfBruteForce = new MethodOfBruteForce();
        final EulerSolution methodOfInclusionExclusion = new MethodOfInclusionExclusion();
        // System.out.println(methodOfBruteForce.solve()); 
        System.out.println(methodOfInclusionExclusion.solve());
        return;
    }
}

class MethodOfBruteForce implements EulerSolution{
    public String solve(){
    	int sumOfMultiplesOf3Or5 = 0;
    	for(int number = 1; number < 1000; ++number){
    		if(number % 3 == 0 || number % 5 == 0) sumOfMultiplesOf3Or5 += number;
    	}

        return String.valueOf(sumOfMultiplesOf3Or5);
    }
}

class MethodOfInclusionExclusion implements EulerSolution{
    public String solve(){
        int sumOfMultiplesOf3Or5 = sumOfMultiplesOf(3) + sumOfMultiplesOf(5) - sumOfMultiplesOf(LCMof(3, 5));

        return String.valueOf(sumOfMultiplesOf3Or5);
    }


    public int sumOfMultiplesOf(int N){
        int m = 999 / N;

        return N * m * (m + 1) / 2;
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
	public String solve();
}


