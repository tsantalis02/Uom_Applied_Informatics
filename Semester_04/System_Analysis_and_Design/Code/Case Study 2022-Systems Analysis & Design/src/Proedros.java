

	import java.util.ArrayList;

	public class Proedros {
		
		private String email;
		private ArrayList<String> ListaAitisewn;
		private ArrayList<String> ListaMelwn;
		private ArrayList<String> ListaEisigisewn;
		private String password;
		private static Proedros single_instance = null;

		private Proedros(String email,String password) {
			this.email = email;
			this.password = password;
		}
		public static Proedros arxikopoihse_Proedros(String email,String password) {
			if(single_instance == null) {
				single_instance = new Proedros(email,password);
			}
			return single_instance;
		}
		public static Proedros Get_instance() {
			if(single_instance == null) {
				System.out.println("prepei na arxikopoihseis ton proedro");	
			}
			return single_instance;
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

		
		public void anathesi_Eisigisis(Melos eisigitis,Aitisi aitisi) {
			
			
			if (aitisi.getVisibilityPhase() == FaseisAitisis.ORISMOS_EISIGITI) {
				if (aitisi.getEisigisi().getListaMelwn().contains(eisigitis)) {

					aitisi.getEisigisi().setEisigitis(eisigitis);
					aitisi.getEisigisi().apomakryne_melos(eisigitis);
					aitisi.setVisibilityPhase(FaseisAitisis.EISIGISH);
				} else {
					System.out.println("Yparxei sygkroysh symferontos opote denginetai na oristei eisigitis");
				} 
			}else {
				System.out.println("Den exei ginei akoma elegxos symferontwn");
			}
			
		}

		public void Elegxos_Sygkrousis_Symferontwn(Aitisi aitisi) {
			aitisi.setVisibilityPhase(FaseisAitisis.ORISMOS_EISIGITI);
		}
		
		public void Psifoforia(Aitisi aitisi) {
			aitisi.setVisibilityPhase(FaseisAitisis.APOFASH);
			aitisi.getEisigisi().calc_result();
		}
		public void psifos_Eisigisis(int psifos, Eisigisi eisigisi) {

			eisigisi.registerVote(psifos);
		}

		
		public boolean syggrafi_Apofasis(String text, Apofasi apofasi) {
			
			apofasi.setText(text);
			return true;
		}

		
		public boolean apokleismos_melous(Melos melos,Eisigisi e) {
			
			e.apomakryne_melos(melos);
			return true;
		}

		
		public void ypografi_Apofasis(Aitisi aitisi) {
			
			if(aitisi.getVisibilityPhase() != FaseisAitisis.APOFASH )return ;
			aitisi.getApofasi().setText(aitisi.getApofasi().getText().concat("\nO Ypografwn: \n " + this.getEmail()));
			aitisi.setVisibilityPhase(FaseisAitisis.ENHMERWSH_EREYNHTH);

		}
		
		
		public void printData() {
			System.out.println("PROEDROS: " + this.getEmail() + "password ");
		}

	}

