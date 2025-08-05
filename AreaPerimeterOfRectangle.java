//write a java program to calculate area and perimeter of a rectanlge
import java.util.Scanner;
class AreaPerimeterOfRectangle{
    public static void main(String args[]){
    Scanner scan=new Scanner(System.in);
    System.out.print("Enter length:");
    float length=scan.nextFloat();
    System.out.print("Enter breadth:");
    float breadth=scan.nextFloat();
    float area=length*breadth;
    float perimeter=2*(length+breadth);
    System.out.print("Area of rectangle:"+area);
    System.out.print("\nPerimeter of rectangle:"+perimeter);
}
}