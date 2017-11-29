import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
//1. One way is to use a recursive function
//2. Other is to use a static variable and build an array of objects of size n 
//Use the constructor of the object to increment and print the values.
//Note: The second method does not work in JAVA! It works in C++
public class Test17_1PrintNumbersWithoutLoop {
	static class PrintNumbers {
		static int y;
		PrintNumbers() {
			y++;
			System.out.println(y);
		}
	}
	public static void main(String[]args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++) {
			int n=Integer.parseInt(br.readLine());
			//Without using recursion

//			PrintNumbers pn[]=new PrintNumbers[n];
			
			//Using recursion
			int x=1;
			printNumsRecursion(x,n);
			
		}
	}
	
	private static void printNumsRecursion(int x,int n) {
		if(x<=n){
			System.out.println(x);
			printNumsRecursion(x+1,n);
		}
		else return;
	}
}
