import java.io.*;
import java.util.*;

class Test11_2ChefAndNumbers {
	public static void main(String[]args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		Scanner in=new Scanner(System.in);

		long n=in.nextInt();
		long num=0;
		long x=n-97;
		if(x<=0)
			x=1;
		for(long i=x;i<n;i++) {
			long sum_digits=sumDigits(i);
			long sum_sum_digits=sumDigits(sum_digits);
			if(i+sum_digits+sum_sum_digits==n)
				num++;
		}
		System.out.println(num);

	}

	private static long sumDigits(long num) {
		long sum=0;
		while(num>0) {
			sum+=(num%10);
			num=num/10;
		}
		return sum;
	}

}
