package model;

public class ProdutoEletronico extends Produto {
	private int garantiaMeses;
	private String voltagem;
	
	public ProdutoEletronico(String codigo, String nome, int quantidade, double preco, int garantiaMeses,
			String voltagem) {
		super(codigo, nome, quantidade, preco);
		this.garantiaMeses = garantiaMeses;
		this.voltagem = voltagem;
	}

	@Override
	public String exibirDetalhes() {
	    String detalhes = "--- DETALHES PRODUTO ---\n";
	    detalhes += "Nome: " + super.getNome() + "\n";
	    detalhes += "Codigo: " + super.getCodigo() + "\n";
	    detalhes += "Quantidade estoque: " + super.getQuantidade() + "\n";
	    detalhes += "Preco: " + super.getPreco() + "\n";
	    detalhes += "Garantia: " + garantiaMeses + " meses" + "\n";
	    detalhes += "Voltagem eletrica: " + voltagem + "\n";
	    
	    return detalhes;
	}
	
	public boolean possuiGarantiaEstendida() {
	    return garantiaMeses > 12;
	}
}
