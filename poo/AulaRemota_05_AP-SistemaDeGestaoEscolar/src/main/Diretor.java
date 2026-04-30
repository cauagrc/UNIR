package main;

public class Diretor extends Usuario {
	private String campus;
	private double salario;
	private int titulacao;
	
	public Diretor(String nome, String cpf, String dataNascimento, double salario, String campus, int titulacao) {
		super(nome, cpf, dataNascimento);
		this.campus = campus;
		this.salario = salario;
		this.titulacao = titulacao;
	}
	
	public String getCampus() {
		return campus;
	}
	public void setCampus(String campus) {
		this.campus = campus;
	}
	public double getSalario() {
		return salario;
	}
	public void setSalario(double salario) {
		this.salario = salario;
	}
	
	@Override
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
