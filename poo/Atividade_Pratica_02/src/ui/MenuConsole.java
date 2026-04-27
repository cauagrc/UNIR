package ui;

import java.time.LocalDate;
import java.util.Scanner;

import model.ProdutoAlimenticio;
import model.ProdutoEletronico;
import model.ProdutoVestuario;
import model.Produto;
import service.Estoque;
import util.FormatadorData;
import util.FormatadorRelatorio;
import util.GeradorCodigo;

public class MenuConsole {
	private Scanner scanner;
	private Estoque estoque;
	
	public MenuConsole(Estoque estoque) {
		this.estoque = estoque;
	}
	
	public void exibirMenu() {
		int op = 0;
		scanner = new Scanner(System.in);
		
		do {
			System.out.println("1) Cadastra produto");
			System.out.println("2) Busca produto");
			System.out.println("3) Lista de produtos");
			System.out.println("4) Lista de produtos com estoque baixo");
			System.out.println("5) Adiciona produto");
			System.out.println("6) Remove produto");
			
			System.out.println("Entre com um numero: ");
			op = scanner.nextInt();
			
			switch (op) {
			case 1: 
				cadastrarProduto();
				break;
			case 2:
				buscarProduto();
				break;
			case 3:
				listarProdutos();
				break;
			case 4:
				listarProdutosEstoqueBaixo();
				break;
			case 5:
				adicionarProduto();
				break;
			case 6:
				removerProduto();
				break;
			}
		} while(op != 0);
	}
	
	public void cadastrarProduto() {
		scanner = new Scanner(System.in);
		
		int op = 0;
		String nome;
		String codigo;
		int quantidade;
		double preco;
		
		System.out.println("Entre com o nome do produto: ");
		nome = scanner.nextLine();
		
		System.out.println("Entre com a quantidade do estoque: ");
		quantidade = scanner.nextInt();
		
		System.out.println("Entre o valor do produto: ");
		preco = scanner.nextDouble();
		
		do {
			System.out.println("Entre com o tipo do produto: ");
			System.out.println("1) Produto Alimenticio");
			System.out.println("2) Produto Eletronico");
			System.out.println("3) Produto Vestuario");
			op = scanner.nextInt();
		} while(op < 1 || op > 3);
		
		Produto produto;
		
		switch (op) {
		case 1: 
			codigo = GeradorCodigo.gerarCodigo("ALI");
			
			LocalDate dataValidadeConvertida = null;
			
			while (dataValidadeConvertida == null) {
		        System.out.println("Entre com a data de validade do produto (dd/MM/yyyy): ");
		        String dataValidade = scanner.next();

		        try {
		            dataValidadeConvertida = FormatadorData.converterData(dataValidade);
		        } catch (Exception e) {
		            System.out.println("Data inválida! Tente novamente.");
		        }
		    }
			
			System.out.println("Entre com o nro do lote: ");
			String lote = scanner.next();
			
			produto = new ProdutoAlimenticio(codigo, nome, quantidade, preco, dataValidadeConvertida, lote);
			break;
		case 2: 
			codigo = GeradorCodigo.gerarCodigo("ELE");
			
			System.out.println("Entre com o tempo de garantia em meses: ");
			int garantiaMeses = scanner.nextInt();
			
			System.out.println("Entre com a voltagem do eletronico: ");
			String voltagem = scanner.next();
			
			produto = new ProdutoEletronico(codigo, nome, quantidade, preco, garantiaMeses, voltagem);
			break;
		case 3: 
			codigo = GeradorCodigo.gerarCodigo("VEST");
			
			System.out.println("Entre com o tamanho: ");
			String tamanho = scanner.next();
			
			System.out.println("Entre com o material do produto: ");
			String material = scanner.next();
			
			produto = new ProdutoVestuario(codigo, nome, quantidade, preco, tamanho, material);
			break;
		default:
			return;
		}
		
		estoque.cadastrarProduto(produto);
	}
	
	public void listarProdutos() {
		System.out.println(FormatadorRelatorio.formatarListaProdutos(estoque.listarProdutos()));
	}
	
	public void listarProdutosEstoqueBaixo() {
		scanner = new Scanner(System.in);
		
		System.out.println("Entre com o numero limite de produtos no estoque: ");
		int limite = scanner.nextInt();
		
		System.out.println(FormatadorRelatorio.formatarRelatorioEstoque(estoque.listarProdutosComEstoqueBaixo(limite)));
	}
	
	public void buscarProduto() {
		scanner = new Scanner(System.in);
		
		System.out.println("Entre com o codigo de busca do produto: ");
		String codigo = scanner.next();
		
		System.out.println(FormatadorRelatorio.formatarProduto(estoque.buscarProdutoPorCodigo(codigo)));
	}
	
	public void adicionarProduto() {
		scanner = new Scanner(System.in);
		
		System.out.println("Entre com o codigo do produto: ");
		String codigo = scanner.next();
		
		System.out.println("Entre com a quantidade de estoque do produto: ");
		int quantidade = scanner.nextInt();
		
		estoque.registrarEntrada(codigo, quantidade);
	}
	
	public void removerProduto() {
		scanner = new Scanner(System.in);
		
		System.out.println("Entre com o codigo do produto: ");
		String codigo = scanner.next();
		
		System.out.println("Entre com a quantidade de estoque do produto: ");
		int quantidade = scanner.nextInt();
		
		estoque.registrarSaida(codigo, quantidade);
	}

	public void init() {
		exibirMenu();
	}
}
