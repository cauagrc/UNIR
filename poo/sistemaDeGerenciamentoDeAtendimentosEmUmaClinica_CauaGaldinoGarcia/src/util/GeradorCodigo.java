package util;

public class GeradorCodigo {
	private static int sequencial = 1;
	
	public static String gerarCodigo(String prefixo) {
		//Prefixo = COM-001 ou ESPC-092
		String codigo = prefixo + "-";
		
		if(sequencial > 9) {
			codigo += "0" + sequencial;
		} 
		else {
			codigo += "00" + sequencial;
		}
		
		sequencial++;
		
		return codigo;
	}
}
