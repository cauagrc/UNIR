package main;

public class Casa {
	private String cor;
	
	Porta[] porta = { new Porta(true), new Porta(true), new Porta(true) };
	
	
	public int quantasPortasEstaoAbertas() {
		int i, count = 0;
		
		for(i = 0; i < porta.length; i++) {
			if(porta[i].estaAberta()) {
				count++;
			}
		}
		
		return count;
	}
}
