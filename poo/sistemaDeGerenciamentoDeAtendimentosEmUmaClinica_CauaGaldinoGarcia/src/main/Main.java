package main;

import model.AtendimentoComum;
import model.AtendimentoEspecializado;
import model.Atendimento;
import service.Controladora;
import util.GeradorCodigo;

public class Main {

	public static void main(String[] args) {
		Controladora control = new Controladora();
		
		//Instanciando com valor negativo
		Atendimento a1 = new AtendimentoComum(GeradorCodigo.gerarCodigo("COM"), "Caua", "10/08/2026", -50, false, "Dr. 1", "Dermatologista", 2);
		//Instanciando com todos valores corretos
		Atendimento a2 = new AtendimentoEspecializado(GeradorCodigo.gerarCodigo("ESPC"), "Romulo", "08/12/2026", 50, true, "Urologista", 2, false);
		Atendimento a3 = new AtendimentoComum(GeradorCodigo.gerarCodigo("COM"), "Gustavo", "05/05/2026", 50, true, "Dr. 1", "Dermatologista", 2);
		Atendimento a4 = new AtendimentoEspecializado(GeradorCodigo.gerarCodigo("ESPC"), "Henrique", "23/06/2026", 150, true, "Facial", 3, true);
		Atendimento a5 = new AtendimentoEspecializado(GeradorCodigo.gerarCodigo("ESPC"), "Paula", "30/05/2026", 100, false, "Preenchimento Labial", 2, true);
		
		control.cadastrarAtendimento(a1);
		a1.exibirDetalhes();
		control.cadastrarAtendimento(a2);
		
		//Cadastrando e logo em seguida cancelando
		control.cadastrarAtendimento(a3);
		a3.exibirDetalhes();
		a3.registrarCancelamento();
		a3.exibirDetalhes();
		
		control.cadastrarAtendimento(a4);
		control.cadastrarAtendimento(a5);
		a5.exibirDetalhes();
		control.cadastrarAtendimento(a2);
		
		control.relatorioGeral();
		
		//Buscando para verificar se realmente nao registrou no sistema.
		control.busca(a1.getCodigo());
	}

}
