package main;

import java.util.ArrayList;
import java.util.List;

public class Projeto {
	private String nome;
	private List<Desenvolvedor> desenvolvedores;
	
	public Projeto(String nome) {
		this.nome = nome;
		this.desenvolvedores = new ArrayList<Desenvolvedor>();
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public List<Desenvolvedor> getDesenvolvedores() {
		return desenvolvedores;
	}

	public void setDesenvolvedores(List<Desenvolvedor> desenvolvedores) {
		this.desenvolvedores = desenvolvedores;
	}
	
	public void addDesenvolvedor(Desenvolvedor developer) {
		desenvolvedores.add(developer);
	}
	
	public void addDesenvolvedor(String nome, String cargo, int anosExperiencia) {
		Desenvolvedor developer = new Desenvolvedor(nome, cargo, anosExperiencia);
		
		desenvolvedores.add(developer);
	}
	
	public void addDesenvolvedor(Desenvolvedor... developers) {
		for(Desenvolvedor developer : developers) {
			desenvolvedores.add(developer);
		}
	}
}