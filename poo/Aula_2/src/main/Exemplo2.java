package main;

import java.util.Scanner;

public class Exemplo2 {
	
	public static void main(String[] args) {
		Scanner entrada = new Scanner(System.in);
		System.out.println("Insira um mês: ");
		String mes = entrada.nextLine().toLowerCase();
		String estacao = "";
		
		switch(mes) {
		case "janeiro": 
		case "fevereiro":
		case "março":
		case "abril":
		case "maio":
			estacao = "Verão";
			break;
		default:
			System.out.println("Não há um mês correspondente.");
		}
		
		System.out.println("Estacao correspondente: " + estacao);
	}
	
}
