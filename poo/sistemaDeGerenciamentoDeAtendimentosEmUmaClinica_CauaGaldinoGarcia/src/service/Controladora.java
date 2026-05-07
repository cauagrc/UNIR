package service;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

import model.Atendimento;
import util.FormatadorRelatorio;
import util.FormatadorValor;

public class Controladora {
	HashMap<String, Atendimento> atendimentosMap;
	List<Atendimento> atendimentosList;
	
	public Controladora() {
		this.atendimentosMap = new HashMap<String, Atendimento>();
		this.atendimentosList = new ArrayList<Atendimento>();
	}
	
	public void cadastrarAtendimento(Atendimento atendimento) {
		if(atendimentosMap.containsKey(atendimento.getCodigo())) {
			System.out.println("ERRO: Nao foi possivel cadastrar o mesmo codigo de atendimento");
			return;
		}
		
		if(atendimento.getValorBase() == 0) {
			System.out.println("ERRO: Valor invalido, entao foi definido a 0 e nao foi cadastrado no sistema.");
			return;
		}
		
		atendimentosMap.put(atendimento.getCodigo(), atendimento);
		atendimentosList.add(atendimento);
		
		Atendimento.total++;
		
		System.out.println("SUCESSO: Atendimento registrado com sucesso");
	}
	
	public Atendimento buscarCodigo(String codigo) {
		return atendimentosMap.get(codigo);
	}
	
	public void busca(String codigo) {
		if(atendimentosMap.containsKey(codigo)) {
			Atendimento atendimento = buscarCodigo(codigo);
			atendimento.exibirDetalhes();
		}
		else {
			System.out.println("\n\nERRO: Código  não encontrado");
		}
	}
	
	public List<Atendimento> listarAtendimentos() {
		return atendimentosList;
	}
	
	public double calcularValorTotal() {
		double total = 0;
		
		for(Atendimento atendimento : this.listarAtendimentos()) {
			if(atendimento.getStatus() == "AGENDADO" || atendimento.getStatus() == "REALIZADO") {
				total += atendimento.calcularValorFinal();
			}
		}
		
		return total;
	}
	
	public void relatorioGeral() {
		System.out.println(FormatadorRelatorio.formatarRelatorioGeral(this.listarAtendimentos()));
		System.out.println("TOTAL DE ATENDIMENTOS: " + Atendimento.total);
		System.out.println("\nVALOR TOTAL:" + String.format(" R$ %.2f.", this.calcularValorTotal()));
	}
}
