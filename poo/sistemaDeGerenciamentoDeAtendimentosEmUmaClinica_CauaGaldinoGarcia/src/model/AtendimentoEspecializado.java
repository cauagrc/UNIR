package model;

import util.FormatadorValor;

public class AtendimentoEspecializado extends Atendimento {
	private String tipoProcedimento;
	private int nivelComplexidade;
	private boolean acompanhamentoPos;
	
	public AtendimentoEspecializado(String codigo, String paciente, String data, double valorBase, boolean convenio,
			String tipoProcedimento, int nivelComplexidade, boolean acompanhamentoPos) {
		super(codigo, paciente, data, valorBase, convenio);
		
		this.tipoProcedimento = tipoProcedimento;
		this.nivelComplexidade = nivelComplexidade;
		this.acompanhamentoPos = acompanhamentoPos;
	}

	@Override
	public void exibirDetalhes() {
		System.out.println("==== ATENDIMENTO ESPECIALIZADO ====\n");
		System.out.println("Paciente: " + super.getPaciente());
		System.out.println("Codigo de Atendimento: " + super.getCodigo());
		System.out.println("Procedimento: " + this.tipoProcedimento);
		System.out.println("Complexidade: " + this.nivelComplexidade);
		System.out.println("Acompanhamento Posterior: " + String.format(this.acompanhamentoPos == true ? "Sim" : "Não"));
		System.out.println("Tem convenio: " + String.format(super.isConvenio() == true ? "Sim" : "Não"));
		System.out.println("Atendimento" + super.getStatus());
		System.out.println("VALOR FINAL:" + FormatadorValor.formatarValor(this));
	}

	@Override
	public double calcularValorFinal() {
		if(super.isConvenio()) {
			return super.getValorBase() * this.nivelComplexidade * 0.9;
		} else {
			return super.getValorBase() * this.nivelComplexidade;
		}
	}

}
