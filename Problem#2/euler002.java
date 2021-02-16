public class euler002 {
    public static void main(String[] args){
        final MethodOfGeneratingOddFibonacci methodOfGeneratingOddFibonacci = new MethodOfGeneratingOddFibonacci();
        final MethodOfBruteForce methodOfBruteForce = new MethodOfBruteForce();
        System.out.println(methodOfBruteForce.solve());
        System.out.println(methodOfGeneratingOddFibonacci.solve());
        return;
    }
}

class MethodOfGeneratingOddFibonacci implements EulerSolution {
    public String solve(){
        final int maxLimit = 4000000;
        int sumOfEvenFibonacci = 0;
        for(int last = 1, secondLast = 1, util; ; ){
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
    public String solve(){
        final int maxLimit = 4000000;
        int sumOfEvenFibonacci = 0;
        for(int last = 1, secondLast = 1, current; ; ){
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
    public String solve();
}