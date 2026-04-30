package main;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(MathOperations.potencia(2, 3));
		
		System.out.println();
		
		int base [] = {1, 2, 3, 4};
		
		for(int b : MathOperations.potencia(base, 2)) {
			System.out.println(b);
		}
	}

}
