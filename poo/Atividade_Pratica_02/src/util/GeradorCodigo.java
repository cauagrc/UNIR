package util;

public class GeradorCodigo {
	private static int sequencial = 1;
	
	public static String gerarCodigo(String prefixo) {
		String codigo = prefixo;
		
		if(sequencial > 9) {
			codigo += "0" + sequencial;
		} 
		else {
			codigo += "00" + sequencial;
		}
		
		return codigo;
	}
}
