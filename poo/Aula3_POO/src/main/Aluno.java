package main;

public class Aluno {

	private String nome;
	private String curso;
	private String matricula;
	
	void visualizarDados() {
		System.out.println("Nome: " + nome);
		System.out.println("Matricula: " + matricula);
		System.out.println("Curso: " + curso);
	}
	
	void setName(String nome) {
		this.nome = nome;
	}
	
	void setMatricula(String matricula) {
		this.matricula = matricula;
	}
	
	void setCurso(String curso) {
		this.curso = curso;
	}

}
