package main;

import java.util.List;
import java.util.ArrayList;

public class Professor extends Usuario {
    private List<Disciplina> disciplinas;
    private int titulacao;

    public Professor(String nome, String cpf, String dataNascimento, int titulacao) {
		super(nome, cpf, dataNascimento);
		this.titulacao = titulacao;
	}

	public void adicionarDisciplina(Disciplina disciplina) {
        this.disciplinas.add(disciplina);
    }
    
    public void vizualizarNotasAlunos() {
    	for(Disciplina disciplina : this.disciplinas) {
    		
    	}
    }
    
    public void vizualizarAluno(String nomeDisciplina, Aluno aluno) {
    	for (Disciplina disciplina : aluno.getDisciplinas()) {
    		if(disciplina.getNome().equalsIgnoreCase(nomeDisciplina)) {
    			
    		}
    	}
    }
    
    public void adicionarNota(Aluno aluno, double nota1, double nota2, int cod) {
    	
    }
    
    public double calcularSalario(int qtdHoras, double valorHora) {
    	double salario = qtdHoras * valorHora;
		
		if(titulacao == 1) {
			salario += (salario * 0.5);
		} else if(titulacao == 2) {
			salario += (salario * 0.15);
		} else if(titulacao == 3) {
			salario += (salario * 0.30);
		}
		
		return salario;
	}
}