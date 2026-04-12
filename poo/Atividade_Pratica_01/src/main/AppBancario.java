package main;

import java.util.HashMap;

public class AppBancario {
	final HashMap<String, Conta> contasBancarias = new HashMap<>();
	private Conta contaLogada;
	private static int transacoesRealizadas = 0;
	
	public void cadastrarConta(Conta conta) {
		contasBancarias.put(conta.getNumConta(), conta);
	}
	
	
	public void logar(String numeroConta, String senha) {
		Conta conta = contasBancarias.get(numeroConta);
		
		if(conta != null && conta.validarSenha(senha)) {
			contaLogada = conta;
			System.out.println("NRO CONTA = " + contaLogada.getNumConta() + " NOME = " + contaLogada.getNome());
			contaLogada.exibirAvisoSeguranca();
		} 
		else {
			System.out.println("Erro na tentativa de login.");
		}
	}
	
	public void depositar(double valor) {
		if (contaLogada != null) {
			contaLogada.depositar(valor);
			transacoesRealizadas++;
		}
	}
	
	public void transferir(String contaDestino, double valor) {
		if(contaLogada != null) {
			Conta destino = contasBancarias.get(contaDestino);
			
			if(destino != null) {
				if(destino != contaLogada) {
					boolean saqueRealizado = contaLogada.sacar(valor);
					
					if(saqueRealizado) {
						destino.depositar(valor, contaLogada.getNome());
						transacoesRealizadas++;
					}
				}
			}
		}
		else {
			System.out.println("Erro na transferencia.");
		}
	}
	
	public static void exibirMetricas() {
		System.out.println("Total de operacoes: " + transacoesRealizadas);
	}
}