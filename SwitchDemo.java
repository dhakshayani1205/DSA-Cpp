
/* This is an example of a switch case statement*/
class SwitchDemo {
public static void main(String[] args) {
int weekday = Integer.parseInt(args[0]);
switch(weekday) {
default: System.out.println("Invalid day");
case 1: System.out.println("Sunday"); break;
case 2: System.out.println("Monday"); break;
case 3: System.out.println("Tuesday"); break;
case 4: System.out.println("Wednesday"); break;
case 5: System.out.println("Thursday"); break;
case 6: System.out.println("Friday"); break;
case 7: System.out.println("Saturday"); break;
}
}
} 
