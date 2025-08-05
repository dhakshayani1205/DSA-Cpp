//write a java program to check weather a number is divisible by both 5 and 11
import java.util.Scanner;
class DivisibleBy5And11{
    public static void main(String args[]){
        Scanner scan=new Scanner(System.in);
        System.out.print("Enter a number:");
        int num=scan.nextInt();
        if(num%5==0 && num%11==0)
        {
            System.out.println("The given number is divisible by 5 and 11");
        }
        else{
            System.out.println("The given number is not divisible by 5 and 11");
        }
    }
}