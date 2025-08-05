class Factorial{
public  static void main(String a[]){
int number;
number=Integer.parseInt(a[0]);
int res=factCalc(number);
System.out.println("fact="+"number"+res);
}
static int factCalc(int n){
int fact=1;
while(n<=1){
fact=fact*n;
n=n-1;
}
return fact;
}
}