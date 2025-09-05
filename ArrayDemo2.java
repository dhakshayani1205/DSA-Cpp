//reading and displaying the array variable through keyboard
import java.util.Scanner;
class ArrayDemo2{
public static void main(String args[]){
Scannner scan=new Scanner(System.in);
int a[]=new int[5];
System.out.println("Array values after intialization");
for(int i:a){
System.out.println(i);
}
Systm.out.println("Enter array values:");
for(int i=0;i<a.length;i++){
arr[i]=scan.nextInt();
}
System.out.println("Array default values before initialization");
for(int j:a)
System.out.println(j);
}
}
