package util;

import java.util.List;

import model.Produto;

public class FormatadorRelatorio {
	public static String formatarProduto(Produto produto) {
		String detalhes = "--- PRODUTO DETALHES ---\n";
		
		detalhes += "Nome: " + produto.getNome() + "\n";
		detalhes += "Codigo: " + produto.getCodigo() + "\n";
		detalhes += "Quantidade estoque: " + produto.getQuantidade() + "\n";
		detalhes += "Preco: " + produto.getPreco() + "\n";
		
		return detalhes;
	}
	
	public static String formatarListaProdutos(List<Produto> produtos) {
		String lista = "--- LISTA DE PRODUTOS ---\n";
		
		for(Produto produto : produtos) {
			lista += "Produto: " + produto.getNome() + " Quantidade estoque: " + produto.getQuantidade() + " Codigo: " + produto.getCodigo() + "\n";
		}
		
		return lista;
	}
	
	public static String formatarRelatorioEstoque(List<Produto> produtos) {
		String relatorio = "--- RELATORIO DE ESTOQUE ---";
		
		for (Produto produto : produtos) {
			relatorio += "Produto = " + produto.getNome() + " Estoque = " + produto.getQuantidade() + "\n";
		}
		
		return relatorio;
	}
}
