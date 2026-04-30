package main;

import java.util.ArrayList;
import java.util.HashMap;

public class Disciplina {
	private String nome;
	private Professor professor;
	private int codigo;
	private HashMap<Aluno, double[]> alunos;
	
	public Disciplina(String nome, Professor professor, int codigo) {
		this.nome = nome;
		this.codigo = codigo;
		this.alunos = new HashMap<Aluno, double[]>();
		professor.adicionarDisciplina(this);
	}
	
	public void exibirDados() {
		System.out.println("Dados da Disciplina: ");
		System.out.println("Nome: " + this.nome);
		System.out.println("Codigo: " + this.codigo);
		System.out.println("Professor: " + this.professor.getNome());
	}
	
	public String getNome() {
		return nome;
	}

	public int getCodigo() {
		return codigo;
	}
	
	public void adicionarNotas(Aluno aluno, double nota1, double nota2) {
		double notas[] = {nota1, nota2};
		
		this.alunos.put(aluno, notas);
	}
	
	public void matricularAluno(Aluno aluno) {
		this.alunos.put(aluno, null);
	}

	public void verNotas() {
		for(Aluno aluno : this.alunos.keySet()) {
			aluno.exibirHistorico();
		}
	}
	
	public double [] getNotas(Aluno aluno) {
		return this.alunos.get(aluno);
	}

}	
