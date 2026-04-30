package main;

public class Pessoa {
	private String nome;
	private int idade;
	
	public Pessoa(String nome, int idade) {
		this.nome = nome;
		this.idade = idade;
	}
	
	public String getNome() {
		return this.nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public void fazerAniversario() {
		this.idade = idade + 1;
	}
	
	public int getIdade() {
		return this.idade;
	}
}