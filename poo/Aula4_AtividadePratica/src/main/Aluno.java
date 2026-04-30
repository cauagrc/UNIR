package main;

public class Aluno {
	private String nome;
	private int idade;
	private String matricula;
	
	public Aluno(String nome, int idade, String matricula) {
		this.nome = nome;
		this.idade = idade;
		this.matricula = matricula;
	}
	
	public void setNome(String nome) {
		if(nome.length() < 1) {
			System.out.println("Nome nao pode ser vazio");
		} else {
			this.nome = nome;
		}
	}
	
	public String getNome() {
		return this.nome;
	}
	
	public void setIdade(int idade) {
		if(idade < 0) {
			System.out.println("A idade nao pode ser negativa");
		} else {
			this.idade = idade;
		}
	}
	
	public int getIdade() {
		return this.idade;
	}

	public String getMatricula() {
		return this.matricula;
	}

	public void setMatricula(String matricula) {
		this.matricula = matricula;
	}
	
	public void getDados() {
		System.out.println("Nome: " + this.nome);
		System.out.println("Idade: " + this.idade);
		System.out.println("Matricula: " + this.matricula);
	}
	
}
