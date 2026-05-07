package model;

import util.FormatadorValor;

public class AtendimentoComum extends Atendimento {
	private String medico;
	private String especialidade;
	private int duracao;
	
	public AtendimentoComum(String codigo, String paciente, String data, double valorBase, boolean convenio, 
			String medico, String especialidade, int duracao) {
		super(codigo, paciente, data, valorBase, convenio);
		
		this.medico = medico;
		this.especialidade = especialidade;
		this.duracao = duracao;
	}
	
	public String getMedico() {
		return medico;
	}

	public void setMedico(String medico) {
		this.medico = medico;
	}

	public String getEspecialidade() {
		return especialidade;
	}

	public void setEspecialidade(String especialidade) {
		this.especialidade = especialidade;
	}

	public int getDuracao() {
		return duracao;
	}

	public void setDuracao(int duracao) {
		this.duracao = duracao;
	}

	@Override
	public void exibirDetalhes() {	
		System.out.println("==== ATENDIMENTO ====\n");
		System.out.println("Paciente: " + super.getPaciente());
		System.out.println("Codigo de Atendimento: " + super.getCodigo());
		System.out.println("Medico: " + this.medico);
		System.out.println("Especialidade: " + this.especialidade);
		System.out.println("Tem convenio: " + String.format(super.isConvenio() == true ? "Sim" : "Não"));
		System.out.println("Data: " + super.getData());
		System.out.println("Duracao de " + this.duracao + " horas");
		System.out.println("Atendimento: " + super.getStatus());
		System.out.println("VALOR FINAL:" + FormatadorValor.formatarValor(this));
	}

	@Override
	public double calcularValorFinal() {
		if(super.isConvenio()) {
			return super.getValorBase() * duracao * 0.5;
		} else {
			return super.getValorBase() * duracao;
		}
	}
	
}
