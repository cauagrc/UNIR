package main;

import java.util.ArrayList;
import java.util.List;

public class Estudio {
	private String nome;
	private List<Projeto> projetos;
	
	public Estudio(String nome) {
		super();
		this.nome = nome;
		this.projetos = new ArrayList<Projeto>();
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public List<Projeto> getProjetos() {
		return projetos;
	}

	public void addProjeto(Projeto projeto) {
		projetos.add(projeto);
	}
	
	public void addProjeto(String nome) {
		Projeto projeto =  new Projeto(nome);
		
		projetos.add(projeto);
	}
}
