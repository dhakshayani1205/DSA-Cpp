//write a java program to print multiplication table of a given number
import java.util.Scanner;
class MultiplicationTable{
    public static void main(String args[]){
        Scanner scan=new Scanner(System.in);
        System.out.print("Enter a number for multiplication table:");
        int num=scan.nextInt();
        System.out.print("Enter range:");
        int range=scan.nextInt();
        for(int i=1;i<=range;i++)
        {
            System.out.print(num+"*"+i+"="+num*i);
            System.out.print("\n");
        }
    }
}