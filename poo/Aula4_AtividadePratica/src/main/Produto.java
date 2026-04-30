package main;

public class Produto {
	private String nome;
	private double preco;
	private int quantidade;
	
	public Produto(String nome, double preco, int amount) {
		super();
		this.nome = nome;
		this.quantidade = amount;
		
		if(preco < 0) {
			System.out.println("O preco nao pode ser negativo");
		} else {
			this.preco = preco;
		}
	}
	
	public void adicionarEstoque(int quantidade) {
		this.quantidade += quantidade;
	}
	
	public void removerEstoque(int quantidade) {
		if(quantidade > this.quantidade) {
			System.out.println("Estoque insuficiente");
		} else {
			this.quantidade -= quantidade;
		}
	}
	
}
