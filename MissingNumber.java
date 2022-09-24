import java.util.Scanner;

public class MissingNumber {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long sum = 0;
        for(int i=1;i<n;i++) {
            sum += sc.nextLong();
        }
        System.out.println(((n*(n+1))/2) - sum);
        sc.close();
    }
}