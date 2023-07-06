import java.util.ArrayList;

public class Lista_Eisigisewn {
	private static Lista_Eisigisewn  single_instance = null;
	private ArrayList<Eisigisi> eisigiseis;

	
	
	public static Lista_Eisigisewn listaEisigiseon() {
		if(single_instance == null) {
			single_instance = new Lista_Eisigisewn();
			
		}
		return single_instance;
	}
	
	private Lista_Eisigisewn() {
		eisigiseis = new ArrayList<Eisigisi>();
	}
	public void prosthiki_Eisigisis(Eisigisi eisigisi) {
		
		eisigiseis.add(eisigisi);
	}
	
	public void printData() {
		for(Eisigisi e: eisigiseis) {
			e.printData();
		}
	}
}
