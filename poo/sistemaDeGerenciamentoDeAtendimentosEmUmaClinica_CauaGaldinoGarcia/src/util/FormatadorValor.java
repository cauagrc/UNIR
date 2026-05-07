package util;

import model.Atendimento;

public class FormatadorValor {
	public static String formatarValor(Atendimento atendimento) {
		return String.format(" R$ %.2f ", atendimento.calcularValorFinal());
	}
}
