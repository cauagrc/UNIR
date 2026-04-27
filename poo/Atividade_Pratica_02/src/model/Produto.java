package model;

public abstract class Produto {
	private final String codigo;
	private String nome;
	private int quantidade = 0;
	private double preco;
	private static int totalProdutos = 0;
	
	public Produto(String codigo, String nome, int quantidade, double preco) {
		this.codigo = codigo;
		this.nome = nome;
		this.entradaEstoque(quantidade);
		this.preco = preco;
		Produto.totalProdutos++;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public int getQuantidade() {
		return quantidade;
	}

	public void setQuantidade(int quantidade) {
		this.quantidade = quantidade;
	}

	public double getPreco() {
		return preco;
	}

	public void setPreco(double preco) {
		this.preco = preco;
	}

	public static int getTotalProdutos() {
		return totalProdutos;
	}

	public String getCodigo() {
		return codigo;
	}
	
	public void saidaEstoque(int quantidade) {
		if(quantidade > this.quantidade) {
			System.out.println("Quantidade superior a quantidade em estoque.");
		}
		else {
			if(quantidade < 0) {
				System.out.println("Quantidade nao e um valor valido.");
			} else {
				this.quantidade -= quantidade;
				System.out.println("Foram removidos " + quantidade + " produtos do estoque.");
			}
		}
	}
	
	public void saidaEstoque(int quantidade, boolean permitirZerar) {
		if(quantidade > this.quantidade) {
			System.out.println("Quantidade superior a quantidade em estoque.");
		}
		else {
			if(quantidade < 0) {
				System.out.println("Quantidade nao e um valor valido.");
			} else {
				this.quantidade -= quantidade;
				
				if(this.quantidade == 0) {
					System.out.println("AVISO: ESTOQUE DO PRODUTO ZERADO.");
				}
				
				System.out.println("Foram removidos " + quantidade + " produtos do estoque.");
			}
		}
	}
	
	public final void entradaEstoque(int quantidade) {
		if(quantidade < 0) {
			System.out.println("Quantidade nao e um valor valido.");
		} else {
			this.quantidade += quantidade;
			System.out.println("Foram adicionados " + quantidade + " produtos no estoque.");
		}
	}
	
	public abstract String exibirDetalhes();
}
