import java.util.Scanner;

public class Repetitions {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int ans = 0;
        int count = 0;
        char prev = s.charAt(0);
        for(int i=0;i<s.length();i++) {
            char c = s.charAt(i);
            if(c==prev) {
                count++;
            }
            if(c!=prev || i==s.length()-1) {
                ans = Math.max(ans,count);
                count = 1;
                prev = c;
            }
        }
        System.out.println(ans);
        sc.close();
    }
}