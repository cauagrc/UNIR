package main;

import java.util.ArrayList;
import java.util.List;

public class Conta {
	private String nome;
	private final int cpf;
	private final String numConta;
	private String senha;
	private double saldo;
	private static int geradorNumero = 1000;
	private final List<String> extrato;
	
	public Conta(String nome, int cpf, String senha) {
		this.nome = nome;
		this.cpf = cpf;
		this.senha = senha;
		//
		this.saldo = 0.0;
		this.extrato = new ArrayList<String>();
		extrato.add("Conta criada");
		this.numConta = gerarNumeroDaConta();
	}
	
	private static String gerarNumeroDaConta() {
		String numConta = geradorNumero + "-0";
		geradorNumero++;
		
		return numConta;
	}

	public final void exibirAvisoSeguranca() {
		System.out.println("AVISO DO APP: Nunca compartilhe sua senha com terceiros.");
	}
	
	public boolean validarSenha(String senha) {
		return this.senha.equals(senha);
	}
	
	public boolean sacar(double valor) {
		if(valor < 0.0 || valor > this.saldo) {
			System.out.println("Erro ao sacar");
			return false;
		} 
		else {
			this.saldo -= valor;
			
			extrato.add("Saque realizado de" + String.format(" R$ %.2f", valor) + ".");
			
			return true;
		}
	}
	
	public boolean depositar(double valor) {
		if (valor < 0.0) {
			System.out.println("Erro ao depositar");
			return false;
		}
		else {
			this.saldo += valor;
			
			extrato.add("Deposito realizado de" + String.format(" R$ %.2f", valor) + ".");
			
			return true;
		}
	}
	
	public boolean depositar(double valor, String origem) {
		if (valor < 0.0) {
			System.out.println("Erro ao depositar");
			return false;
		}
		else {
			this.saldo += valor;
			
			extrato.add("Tranferencia recebida de " + origem + " no valor de " + String.format(" R$ %.2f", valor));
			return true;
		}
	}
	
	public void imprimirExtrato() {
		System.out.println("Nome: " + this.nome);
		for(int i = extrato.size() - 1; i >= 0 ; i--) {
			System.out.println(i + " - " + extrato.get(i));
		}
		System.out.println("Saldo final: " + String.format("R$ %.2f", this.saldo) + ".");
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getSenha() {
		return senha;
	}

	public void setSenha(String senha) {
		this.senha = senha;
	}

	public double getSaldo() {
		return saldo;
	}

	public void setSaldo(double saldo) {
		this.saldo = saldo;
	}

	public String getNumConta() {
		return numConta;
	}
	
}
