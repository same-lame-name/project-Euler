import java.util.Scanner;

public class hackerrankEuler002 {
    public static void main(String[] args){
        final MethodOfGeneratingOddFibonacci methodOfGeneratingOddFibonacci = new MethodOfGeneratingOddFibonacci();
        final MethodOfBruteForce methodOfBruteForce = new MethodOfBruteForce();

        Scanner scanner = new Scanner(System.in);
        int testcases = scanner.nextInt();

        while(testcases-- > 0){
            Long maxLimit = scanner.nextLong();
            // System.out.println(methodOfBruteForce.solve(maxLimit));
            System.out.println(methodOfGeneratingOddFibonacci.solve(maxLimit));
        }

        scanner.close();
        return;
    }
}

class MethodOfGeneratingOddFibonacci implements EulerSolution {
    public String solve(Long maxLimit){
        Long sumOfEvenFibonacci = 0L;
        for(Long last = 1L, secondLast = 1L, util; ; ){
            if(last + secondLast > maxLimit) break;
            sumOfEvenFibonacci += last + secondLast;

            util = secondLast;
            secondLast = secondLast + 2 * last;
            last = 2 * util + 3 * last;
        }

        return String.valueOf(sumOfEvenFibonacci);
    }
}

class MethodOfBruteForce implements EulerSolution{
    public String solve(Long maxLimit){
        Long sumOfEvenFibonacci = 0L;
        for(Long last = 1L, secondLast = 1L, current; ; ){
            current = last + secondLast;
            if(current > maxLimit) break;

            if(current % 2 == 0) sumOfEvenFibonacci += current;
            secondLast = last;
            last = current;
        }

        return String.valueOf(sumOfEvenFibonacci);
    }
}

interface EulerSolution{
    public String solve(Long maxLimit);
}