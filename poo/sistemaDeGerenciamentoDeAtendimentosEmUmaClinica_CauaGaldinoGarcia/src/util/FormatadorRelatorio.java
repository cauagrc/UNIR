package util;

import java.util.List;

import model.Atendimento;
import model.AtendimentoEspecializado;

public class FormatadorRelatorio {
	public static String formatarAtendimento(Atendimento atendimento) {
		String detalhes = "";
		
		detalhes += "\n\nPaciente: " + atendimento.getPaciente();
		detalhes += "\nCodigo de Atendimento: " + atendimento.getCodigo();
		detalhes += "\nValor base: " + atendimento.getValorBase();
		detalhes += "\nData: " + atendimento.getData();
		detalhes += "\nAtendimento " + atendimento.getStatus();
		
		return detalhes;
	}
	
	public static String formatarRelatorioGeral(List<Atendimento> atendimentos) {
		int totalComum = 0;
		int totalEspe = 0;
		int totalCancelado = 0;
		
		String relatorio = "==== RELATORIO GERAL ====";
		
		for(Atendimento atendimento : atendimentos) {
			relatorio += formatarAtendimento(atendimento);
			
			if(atendimento instanceof AtendimentoEspecializado) {
				totalEspe++;
			} else {
				totalComum++;
			}
			
			if(atendimento.getStatus() == "CANCELADO") {
				totalCancelado++;
			}
		}
		
		relatorio += "\n\nTOTAL DE ATENDIMENTOS COMUNS: " + totalComum;
		relatorio += "\nTOTAL DE ATENDIMENTOS ESPECIALIZADOS: " + totalEspe;
		relatorio += "\nTOTAL CANCELADOS: " + totalCancelado;
		
		return relatorio;
	}
} 
