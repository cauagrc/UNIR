package main;

import java.util.HashMap;

public class Escola {
	private String nome;
	private HashMap<String, Aluno> alunos = new HashMap<>();
	
	public Escola(String nome) {
		this.nome = nome;
	}

	public void matricularAluno(Aluno aluno) {
        if (alunos.containsKey(aluno.getMatricula())) {
            System.out.println("Aluno já matriculado!");
        } else {
            alunos.put(aluno.getMatricula(), aluno);
            System.out.println("Aluno matriculado com sucesso!");
        }
    }
	
	public Aluno buscarAluno(String matricula) {
        return alunos.get(matricula);
    }
}
