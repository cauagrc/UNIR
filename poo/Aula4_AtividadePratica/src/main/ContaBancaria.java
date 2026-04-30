package main;

public class ContaBancaria {
	private double saldo;
	private String nomeCliente;
	
	public ContaBancaria(String nomeCliente) {
		this.nomeCliente = nomeCliente;
		this.saldo = 0.0;
	}
	
	public void deposita(double valor) {
		this.saldo += valor;
	}
	
	public void sacar(double valor) {
		if(valor > saldo) {
			System.out.println("Saldo insuficiente");
		} else {
			this.saldo -= valor;
		}
	}
	
	public double getSaldo() {
		return this.saldo;
	}
}
