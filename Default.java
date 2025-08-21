//write a java program to display default values of all primitive data types of java
class Default{
int num;
float f;
double d;
long l;
char c;
short s;
byte b;
boolean m;
public static void main(String args[]){
Default val=new Default();
val.display();
}
void display(){
System.out.println("Int ="+num+"\nDouble="+d+"\nLong="+l+"\nChar="+c+"\nshort="+s+"\nByte="+b+"\nBoolean="+m);
}
}