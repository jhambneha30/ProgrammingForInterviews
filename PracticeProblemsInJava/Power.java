
public class Power {
	public static void main(String[]args) {
		int n=9;
		int base=2;
		int res=pow(base,n);
		int res2=iterativePow(base,n);
		System.out.println(res);
		System.out.println(res2);
	}

	private static int iterativePow(int base, int n) {
		int res=1;
		while(n>=1) {
			if(n%2!=0){
				res=res*base;
			}
			base=base*base;
			n=n/2;
		}
		return res;
	}

	private static int pow(int base, int n) {
		int res=1;
		if(n<=1)
			return base;
		else {
			res=res*pow(base*base,n/2);
			if(n%2!=0)
				res=base*res;
		}
		return res;
		
	}
}
