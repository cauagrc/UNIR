package model;

import java.time.LocalDate;
import java.util.Date;

public class ProdutoAlimenticio extends Produto {
	private LocalDate dataValidade;
	private String lote;
	
	public ProdutoAlimenticio(String codigo, String nome, int quantidade, double preco, LocalDate dataValidade, String lote) {
		super(codigo, nome, quantidade, preco);
		this.dataValidade = dataValidade;
		this.lote = lote;
	}

	@Override
	public String exibirDetalhes() {
	    String detalhes = "--- DETALHES PRODUTO ---\n";
	    detalhes += "Nome: " + super.getNome() + "\n";
	    detalhes += "Codigo: " + super.getCodigo() + "\n";
	    detalhes += "Quantidade estoque: " + super.getQuantidade() + "\n";
	    detalhes += "Preco: " + super.getPreco() + "\n";
	    detalhes += "Data de validade: " + dataValidade + "\n";
	    detalhes += "Lote numero: " + lote + "\n";
	    
	    return detalhes;
	}
	
	public boolean estaVencido() {
	    return dataValidade.isBefore(LocalDate.now());
	}
	
	@Override 
	public void saidaEstoque(int quantidade) {
		if(!this.estaVencido()) {
			super.saidaEstoque(quantidade);
		} 
		else {
			System.out.println("Produto vencido.");
		}
	}
	
	@Override 
	public void saidaEstoque(int quantidade, boolean permitirZerar) {
		if(!this.estaVencido()) {
			super.saidaEstoque(quantidade, permitirZerar);
		}
		else {
			System.out.println("Produto vencido.");
		}
	}
}
