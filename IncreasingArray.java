import java.util.Scanner;

public class IncreasingArray {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long arr[] = new long[n];
        long ans = 0;
        for(int i=0;i<n;i++)
        {
            arr[i] = sc.nextLong();
            if(i>0 && arr[i]<arr[i-1]) {
                ans += arr[i-1] - arr[i];
                arr[i] = arr[i-1];
            } 
        }
        System.out.println(ans);
        sc.close();
    }
}