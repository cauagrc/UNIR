package service;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

import model.Produto;

public class Estoque {
	private HashMap<String, Produto> produtosMap;
	private List<Produto> produtosList;
	
	public Estoque() {
		this.produtosMap = new HashMap<String, Produto>();
		this.produtosList = new ArrayList<Produto>();
	}
	
	public boolean cadastrarProduto(Produto produto) {
		if(produtosMap.containsKey(produto.getCodigo())) {
			System.out.println("Nao foi possivel cadastrar o mesmo codigo novamente.");
			return false;
		}
		
		produtosMap.put(produto.getCodigo(), produto);
		produtosList.add(produto);
		
		System.out.println("PRODUTO ADICIONADO COM SUCESSO");
		System.out.println(produto.exibirDetalhes());
		return true;
	}
	
	public Produto buscarProdutoPorCodigo(String codigo) {
		return produtosMap.get(codigo);
	}
	
	public boolean removerProduto(Produto produto) {
		if(!produtosMap.containsKey(produto.getCodigo())) {
			System.out.println("Produto nao encontrado.");
			return false;
		}
		
		produtosMap.remove(produto.getCodigo());
		produtosList.remove(produto);
		
		return true;
	}
	
	public boolean registrarEntrada(String codigo, int quantidade) {
		if(!produtosMap.containsKey(codigo)) {
			System.out.println("Produto nao encontrado");
			return false;
		}
		
		Produto produto = produtosMap.get(codigo);
		
		produto.entradaEstoque(quantidade);
		
		return true;
	}
	
	public boolean registrarSaida(String codigo, int quantidade) {
		if(!produtosMap.containsKey(codigo)) {
			System.out.println("Produto nao encontrado");
			return false;
		}
		
		Produto produto = produtosMap.get(codigo);
		
		produto.saidaEstoque(quantidade);
		
		return true;
	}
	
	public List<Produto> listarProdutos() {
		return produtosList;
	}
	
	public String gerarRelatorioGeral() {
		String relatorio = "RELATORIO DE PRODUTOS\n\n";
		
		for(Produto produto : this.listarProdutos()) {
			relatorio = relatorio + "Produto = " + produto.getNome() + "Estoque = " + produto.getQuantidade() + "\n";
		}
		
		return relatorio;
	}
	
	public List<Produto> listarProdutosComEstoqueBaixo(int limite) {
		List<Produto> produtosComEstoqueBaixo = new ArrayList<Produto>();
		
		for(Produto produto : this.listarProdutos()) {
			if(produto.getQuantidade() <= limite) {
				produtosComEstoqueBaixo.add(produto);
			}
		}
		
		return produtosComEstoqueBaixo;
	}
}
