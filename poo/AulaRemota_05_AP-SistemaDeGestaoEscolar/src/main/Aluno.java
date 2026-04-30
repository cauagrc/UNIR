package main;

import java.util.ArrayList;

public class Aluno extends Usuario {
    private String matricula;
    private boolean bolsista;
    private ArrayList<Disciplina> disciplinas;
    
	public Aluno(String nome, String cpf, String dataNascimento, String matricula, ArrayList<Disciplina> disciplinas) {
		super(nome, cpf, dataNascimento);
		this.matricula = matricula;
		this.disciplinas = disciplinas;
	}

	public String getMatricula() {
		return matricula;
	}

	public void setMatricula(String matricula) {
		this.matricula = matricula;
	}
    
    public void exibirDados() {
    	
    }
    
    public void vizualizarNotaDisciplina(String nome) {
    	
    }
    
    public void vizualizarNotaDisciplina(int codigo) {
    	
    }
    
    private double calcularMedia(double [] notas) {
		double soma = 0;
		
		for(int i = 0; i < notas.length; i++) {
			soma += soma; 
		}
		
		return soma / 2;
	}
	
	public String mostrarConceito(double media) {
		String conceito;
		
		if(media >= 7 && media <= 10) {
			conceito = "Aprovado";
		} else {
			if(media <= 7 && media >= 5) {
				conceito = "Final"; 
			} else {
				conceito = "Reprovado";
			}
		}
		
		return conceito;
	}
    
    public void exibirHistorico() {
    	System.out.println("---Historico Escolar---");
    	System.out.println("Aluno: " + super.getNome());
    	for(Disciplina disc : this.disciplinas) {
    		//if(disc != null) {
    			System.out.println("Codigo: " + disc.getCodigo());
    			System.out.println("Nome da disciplina: " + disc.getNome());
    			double [] notas = disc.getNotas(this);
    			double media = this.calcularMedia(disc.getNotas(this));
    			System.out.println("Media: " + media);
    			System.out.println("Conceito: " + this.mostrarConceito(media));
    		//}
    	}
    }

	public ArrayList<Disciplina> getDisciplinas() {
		return disciplinas;
	}

	public void setDisciplinas(ArrayList<Disciplina> disciplinas) {
		this.disciplinas = disciplinas;
	}

	@Override
	public double calcularSalario(int qtdHoras, double valorHora) {
		if(this.bolsista) {
			return 700.0;
		} 
		else {
			return 0.0;
		}
	}
}
