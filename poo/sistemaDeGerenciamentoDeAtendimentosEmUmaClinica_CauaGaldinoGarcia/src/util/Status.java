package util;

public class Status {
	private String atual;
	
	public void setStatus(String status) {
		switch (status) {
		case "CANCELADO":
			status = "CANCELADO";
			break;
		case "AGENDADO":
			status = "AGENDADO";
			break;
		case "REALIZADO":
			status = "REALIZADO";
			break;
		default:
			System.out.println("ERRO: " + status + "Nao e aceito");
			break;
		}
		
		this.atual = status; 
	}
	
	public String getStatus() {
		return this.atual; 
	}
}