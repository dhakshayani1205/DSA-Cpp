
/* program to check given age input is eligible to vote or not using if- else*/
class Test2{
public static void main(String[ ] args) {
int age;
age = Integer.parseInt(args[0]);
if(age>18) {
System.out.println("Eligible to vote");
}
else {
System.out.println("Not eligible to vote");
}
}