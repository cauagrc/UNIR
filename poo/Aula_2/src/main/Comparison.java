package main;

import java.util.Scanner;

public class Comparison {
	
	public static void main(String[] args) {
		Scanner entrada = new Scanner(System.in);
		
		int number1, number2;
		
		System.out.println("Insira o primeiro numero: ");
		number1 =  entrada.nextInt();
		
		System.out.println("Entre com o segundo numero: ");
		number2 = entrada.nextInt();
		
		if(number1 > number2) {
			System.out.println("O numero 1 eh maior");
		} else {
			if(number2 > number1) {
				System.out.println("O numero 2 eh maior");
			} else {
				System.out.println("Os numeros sao iguais");
			}
		}
	}
	
}
