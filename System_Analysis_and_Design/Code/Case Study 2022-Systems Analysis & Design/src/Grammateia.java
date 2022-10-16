import java.util.ArrayList;

public class Grammateia {
	private String email;
	private String password;
	private static int current_queue_number = 0;
	public Grammateia(String email,String password) {
		this.email = email;
		this.password = password;
	}
	public String getEmail() {
		return this.email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public String getPassword() {
		return this.password;
	}

	public void setPassword(String password) {
		this.password = password;
	}

	
	public void AnagnosiAitisewnGiaPrwtoElegxo() {
		Lista_Aitisewn listaAitisewn = Lista_Aitisewn.ListaAitisewn();
		listaAitisewn.provoli_Aitisewn(FaseisAitisis.ELEGXOS);
	}
	public boolean protokollisi_Aitisis(Aitisi aitisi) {
		
		if(aitisi.getVisibilityPhase() == FaseisAitisis.ELEGXOS) {
			
			aitisi.setInqueueNumber(++current_queue_number);
			
			aitisi.setVisibilityPhase(FaseisAitisis.ELEGXOS_SYMFERONTWN);
			return true;
		}
		return false;
	}

	
	public boolean aporripsi_Aitisis(Aitisi aitisi) {
		
		if(aitisi.getVisibilityPhase() == FaseisAitisis.ELEGXOS) {
			
			aitisi.setVisibilityPhase(FaseisAitisis.APORRIPSH);
			return true;
		}
		return false;
	}

	
	public void diavase_Aitisi(Aitisi aitisi) {
		
		throw new UnsupportedOperationException();
	}

	
	public boolean enimerwse_Ereuniti(Aitisi aitisi) {
		
		if(aitisi.getEisigisi().getResult()) {
			aitisi.setVisibilityPhase(FaseisAitisis.ENHMERWSH_GIA_APODOXH);
		}else {
			aitisi.setVisibilityPhase(FaseisAitisis.ENHMERWSH_GIA_VELTIWSEIS);
		}
		return true;
	}
	
	public void printData() {
		 System.out.println("Grammateia [email=" + email + ", password=" + password + "]");
	}
}
