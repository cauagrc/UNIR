package main;

public class Porta {
	private boolean aberta;
	private String cor;
	//Altura x Largura 
	private String dimensoes;
	
	public Porta(boolean aberta) {
		this.aberta = aberta;
	}

	public void abre() {
		this.aberta = true;
	}
	
	public void fecha() {
		this.aberta = false;
	}
	
	public void pinta(String cor) {
		this.cor = cor;
	}
	
	public boolean estaAberta() {
		return this.aberta;
	}
}