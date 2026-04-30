package main;

import java.util.Scanner;

public class praticando {
	public static int calcularProduto(int num1, int num2, int num3) {
		return num1 * num2 * num3;
	}
	
	public static int calcularQuadrado(int num) {
		return num * num;
	}
	
	public static int calcularCubo(int num) {
		return num * num * num;
	}
	
	public static void main(String[] args) {
		Scanner entrada = new Scanner(System.in);
		
		/*System.out.println("Entre com o primeiro numero: ");
		int x = entrada.nextInt();
		
		System.out.println("Entre com o segundo numero: ");
		int y = entrada.nextInt();
		
		System.out.println("Entre com o terceiro numero: ");
		int z = entrada.nextInt();*/
		
		int x = 3;
		int y = 3;
		int z = 3;
		
		int produto = calcularProduto(x, y, z);
		System.out.println("O produto desses números é: " + produto);
		
		System.out.println("\n\n");
		
		int quadrado = 0;
		int cubo = 0;
		
		for(int i = 0; i < 10; i++) {
			quadrado = calcularQuadrado(i);
			cubo = calcularCubo(i);
			
			System.out.println("number \t square \t cube");
			System.out.printf("%d \t %d \t\t %d \n", i, quadrado, cubo);
		}
		
		System.out.println("\n\n");
		
		System.out.println("Entre com o seu peso em quilogramas: ");
		double peso = entrada.nextDouble();
		
		System.out.println("Entre com a sua altura em metros: ");
		
	}

}
