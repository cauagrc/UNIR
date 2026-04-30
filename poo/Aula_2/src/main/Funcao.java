package main;

public class Funcao {
	
	public static double calcularArea(double raio) {
		return Math.PI * raio * raio;
	}
	
	public static double calcularPerimetro(double raio) {
		return 2 * Math.PI * raio;
	}

	public static void main(String[] args) {
		double raio = 9.0;
		
		double area = calcularArea(raio);
		double perimetro = calcularPerimetro(raio);
		
		System.out.println("Área do círculo: " + area);
		System.out.println("Perímetro do círculo: " + perimetro);
	}

}
