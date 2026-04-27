package model;

public class ProdutoVestuario extends Produto {
	private String tamanho;
	private String material;
	
	public ProdutoVestuario(String codigo, String nome, int quantidade, double preco, String tamanho, String material) {
		super(codigo, nome, quantidade, preco);
		this.tamanho = tamanho;
		this.material = material;
	}

	@Override
	public String exibirDetalhes() {
	    String detalhes = "--- DETALHES PRODUTO ---\n";
	    detalhes += "Nome: " + super.getNome() + "\n";
	    detalhes += "Codigo: " + super.getCodigo() + "\n";
	    detalhes += "Quantidade estoque: " + super.getQuantidade() + "\n";
	    detalhes += "Preco: " + super.getPreco() + "\n";
	    detalhes += "Tamanho: " + tamanho + "\n";
	    detalhes += "Material: " + material + "\n";
	    
	    return detalhes;
	}
	
	public boolean isTamanhoUnico() {
		return false;
	}
}
