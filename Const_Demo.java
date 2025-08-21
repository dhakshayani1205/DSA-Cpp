class Const_Demo{
	int number;
	Const_Demo(int num){
		number=num;
	}
	Const_Demo(){
		number=900;
	}
	//const_Demo d=cd2,copy constructor: constructor with arguments of class type
	Const_Demo(Const_Demo d){
		number=d.number;
	}

	void print(){
		System.out.println("number="+number);
	}
	public static void main(String args[]){
		Const_Demo cd=new Const_Demo();
		cd.print();

		Const_Demo cd2=new Const_Demo(300);
		cd2.print();

		Const_Demo cd3=new Const_Demo(cd2);
		cd3.print();
}
}