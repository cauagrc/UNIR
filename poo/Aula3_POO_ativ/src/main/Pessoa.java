package main;

public class Pessoa {
	private String nome;
	private int idade;
	
	public Pessoa(String nome, int idade) {
		this.nome = nome;
		this.idade = idade;
	}
	
	void fazAniversario() {
		this.idade = this.idade + 1;
	}
	
	void verificarIdade() {
		System.out.println("Idade: " + idade);
	}
	
}
