package main;

public class MathOperations {
	public static int potencia(int base, int expoente) {
		int resultado = base;
		
		for(int i = 1; i < expoente; i++) {
			resultado *= base;
		}
		
		return resultado;
	}
	
	public static int [] potencia(int base[], int expoente) {
        int resultado[] = new int[base.length];
        
        for (int indice = 0 ; indice < base.length; indice++) {
                resultado[indice] = 1;
                
                for (int i = 1; i <= expoente; i++) {                                
                        resultado[indice] *= base[indice];
                }
        }                        
        
        return resultado;
	}
}