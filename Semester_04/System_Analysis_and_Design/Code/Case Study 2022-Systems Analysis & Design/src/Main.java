

		import java.awt.*;
		import java.io.File;
		import java.util.ArrayList;
		import java.util.Scanner;
		public class Main {
			private static int PSIFOS_YPER = 1;
			private static int PSIFOS_KATA = -1;
			private static Grammateia gr;
			public static void main(String[] args) {
				
				//Object Creation
				Lista_Aitisewn listaAitisewn = Lista_Aitisewn.ListaAitisewn();
				Lista_Melwn listaMelwn = Lista_Melwn.ListaMelwn();
				Lista_Eisigisewn listaEisigiseon = Lista_Eisigisewn.listaEisigiseon();
				Melos m1 = new Melos("giannhs@uom.edu.gr","Mpananies");
				Melos m2 = new Melos("panagiwths@uom.edu.gr","milo");
				Melos m3 = new Melos("giwrgos@uom.edu.gr","aeras");
				Melos m4 = new Melos("votsalos@uom.edu.gr","thalassa");
				
				
				
				Proedros proedros = Proedros.arxikopoihse_Proedros("LinusTorvalds@uom.edu.gr", "i am the father of computer science");
			
				Ereunitis e1 = new Ereunitis("mejustin@uom.edu.gr","galapagos");
				Ereunitis e2 = new Ereunitis("TonyMontana@uom.edu.gr","communicatepls");
				Ereunitis e3 = new Ereunitis("JordanPeterson@uom.edu.gr","psycho-logy");
				
				Lista_Arxeiwn la = new Lista_Arxeiwn();
				la.prosthiki_Arxeiou("xarti.pdf");
				la.prosthiki_Arxeiou("dikaiologitika.docx");
				Lista_Arxeiwn la1 = new Lista_Arxeiwn();
				la1.prosthiki_Arxeiou("This_xarti.pdf");
				la1.prosthiki_Arxeiou("dikaiologitika.docx");
				Lista_Arxeiwn la2 = new Lista_Arxeiwn();
				la2.prosthiki_Arxeiou("psych.pdf");
				la2.prosthiki_Arxeiou("dikaiologitika.docx");
				
				
				Lista_Arxeiwn la3 = new Lista_Arxeiwn();
				
				Aitisi a1 = new Aitisi(e1,"On the Origin of Species","evolutionary biology",la);
				Aitisi a2 = new Aitisi(e2,"A mathematical theory of communication","information theory",la1);
				Aitisi a3 = new Aitisi(e3,"The Neuro-Psychoses of Defence","psychology",la2);
				Aitisi a4 = new Aitisi(e3,"On the Psychical Mechanism of Hysterical Phenomena","psychology",la3);
				
				gr = new Grammateia("daisecr@uom.edu.gr","uomcampus");

				e1.ypovolli_Aitisis(a1);e2.ypovolli_Aitisis(a2);e3.ypovolli_Aitisis(a3);
				gr.AnagnosiAitisewnGiaPrwtoElegxo();
				
				
				
				printScenarioMenu();
				
				Scanner sc = new Scanner(System.in);
				int choice = sc.nextInt();
				switch (choice){
					case 1:
						scenario1(a1);
						break;
					case 2:
						scenario2(a2);
						break;
					case 3:
						scenario3(a3);
						break;
					case 4:
						printKatalogous();
						break;
						
				}
				while(choice != 4) {
					printScenarioMenu();
					choice = sc.nextInt();
					switch (choice){
						case 1:
							scenario1(a1);
							break;
						case 2:
							scenario2(a2);
							break;
						case 3:
							scenario3(a3);
							break;
						case 4:
							printKatalogous();
							break;
							
					}	
				}
				
			
				
			}
			
			private static void printKatalogous() {
				try {
					Lista_Aitisewn listaAitisewn = Lista_Aitisewn.ListaAitisewn();
					Lista_Melwn listaMelwn = Lista_Melwn.ListaMelwn();
					Lista_Eisigisewn listaEisigiseon = Lista_Eisigisewn.listaEisigiseon();
					System.out.println("Εμφάνιση περιεχομένων των καταλόγων δεδομένων");
					System.out.println("Δεδομένα Λίστας Αιτήσεων\n");
					listaAitisewn.printData();
					Thread.sleep(4000);
					System.out.println("Δεδομένα Λίστας Εισηγήσεων\n");
					listaEisigiseon.printData();
					Thread.sleep(4000);
					System.out.println("Δεδομένα Λίστας Μελών\n");
					listaMelwn.printData();
					Thread.sleep(4000);
					
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
			
			private static void scenario2(Aitisi a) {
				//Σενάριο 2: Η αίτηση ελέγχεται, απορρίπτεται και εμφανίζονται όλες οι αιτήσεις που έχει υποβάλλει ο ερευνητής 
				Proedros proedros = Proedros.Get_instance();
				Ereunitis e = a.getEreunitis();
				try {
					System.out.println("Η γραμματεία ελέγχει την αίτηση , προκύπτει ότι είναι ελλιπής και την απορρίπτει \n");
					gr.aporripsi_Aitisis(a);
					Thread.sleep(2000);
					
					System.out.println("Ο ερευνητής πρέπει να δει τις αιτήσεις του για να δει την εξέλιξη όσων έχει υποβάλλει \n");
					e.print_Aitiseis();
					Thread.sleep(2000);
				} catch (InterruptedException e1) {
					e1.printStackTrace();
				}
				
			}

			private static void scenario3(Aitisi a) {
				
				//Σενάριο 3: Ο ερευνητής πρέπει να δει τις αιτήσεις του για να δει το αποτέλεδμα όσων έχει υποβάλλει.
				try {
					System.out.println("Ψάχνουμε τα μέλη και τον πρόεδρο\n");
					Proedros proedros = Proedros.Get_instance();
					Lista_Melwn listaMelwn = Lista_Melwn.ListaMelwn();
					Melos m1 = listaMelwn.getMeli_EHDE().get(0);
					Melos m2 = listaMelwn.getMeli_EHDE().get(1);
					Melos m3 = listaMelwn.getMeli_EHDE().get(2);
					Melos m4 = listaMelwn.getMeli_EHDE().get(3);
					Ereunitis e = a.getEreunitis();
					Thread.sleep(2000);
					
					System.out.println("Η γραμματεία πρωτοκολλεί την αίτηση\n");
					Thread.sleep(2000);
					gr.protokollisi_Aitisis(a);
					
	

				System.out.println("Ο πρόεδρος κάνει έλεγχο σύγκρουσης συμφερόντων\n");
				Thread.sleep(2000);
				proedros.apokleismos_melous(m3, a.getEisigisi());
				System.out.println("Ο πρόεδρος απέκλεισε το μέλος:" + m1);
				Thread.sleep(2000);
				
				System.out.println("Ο πρόεδρος ολοκληρώνει τον έλεγχο σύγκρουσης συμφερόντων.\n");
				Thread.sleep(2000);
				proedros.Elegxos_Sygkrousis_Symferontwn(a);
				
				
				System.out.println("Ο πρόεδρος ορίζει τον εισηγητή για την αίτηση.");
				Thread.sleep(2000);
				proedros.anathesi_Eisigisis(m1,a);
				System.out.println("Εισηγητής ορίστηκε το μέλος: "+ m1);
				Thread.sleep(2000);
				
				System.out.println("Περιμένουμε τον εισηγητή να δημιουργήσει την εισήγηση.");
				Thread.sleep(2000);
				m1.dimiourgiseEisigisi(a,"He is just doing maths nothing of ethics that should concern us");

				System.out.println("Συνεχίζουμε με την ψηφοφορία.");
				Thread.sleep(2000);
				proedros.psifos_Eisigisis(PSIFOS_YPER, a.getEisigisi());
				m2.psifiseGiaEisigisiAitisis(a, PSIFOS_YPER);
				m4.psifiseGiaEisigisiAitisis(a, PSIFOS_YPER);
				
				System.out.println("Ψηφίσανε όλοι και ο πρόεδρος κλείνει την ψηφοφορία");
				Thread.sleep(2000);
				proedros.Psifoforia(a);
				
				String message2 = (a.getEisigisi().getResult()) ? "Ginetai Apodekth":"Aporriptetai";
				System.out.println(a.getTitle() + " " + message2);
				System.out.println(a.getEisigisi().getResult());
				Thread.sleep(2000);
				
				System.out.println("Ο πρόεδρος θα γράψει την απόφαση για την αίτηση.");
				Thread.sleep(2000);
				proedros.syggrafi_Apofasis("Η αίτηση γίνεται δεκτή καθώς δεν τίθεται κανένα θέμα ηθικής", a.getApofasi());
				proedros.ypografi_Apofasis(a);
				
				
				System.out.println("Ο πρόεδρος υπέγραψε.\n Αποστέλλεται ενημερωτικό μήνυμα στον ερευνητή\n");
				Thread.sleep(2000);
				gr.enimerwse_Ereuniti(a);
				
				Thread.sleep(2000);
				System.out.println("Ο ερευνητής πρέπει να ελέγξει τις αιτήσεις του για να δει την κατάσταση τους\n");
				e.print_Aitiseis();
				Thread.sleep(2000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}

		private static void scenario1(Aitisi a) {
			//Σενάριο 1: 
			try {
				System.out.println("Ψάχνουμε τον πρόεδρο, τα μέλη και τον ερευνητή\n");
				Proedros proedros = Proedros.Get_instance();
				Lista_Melwn listaMelwn = Lista_Melwn.ListaMelwn();
				Melos m1 = listaMelwn.getMeli_EHDE().get(0);
				Melos m2 = listaMelwn.getMeli_EHDE().get(1);
				Melos m3 = listaMelwn.getMeli_EHDE().get(2);
				Melos m4 = listaMelwn.getMeli_EHDE().get(3);
				Ereunitis e = a.getEreunitis();
				Thread.sleep(2000);
				
				System.out.println("Η γραμματεία πρέπει να πρωτοκολλήσει την αίτηση.\n");
				gr.protokollisi_Aitisis(a);
				Thread.sleep(2000);
				
				
				System.out.println("Ο πρόεδρος κάνει έλεγχο σύγκρουσης συμφερόντων.\n");
				Thread.sleep(2000);
				proedros.apokleismos_melous(m1, a.getEisigisi());
				System.out.println("Ο Πρόεδρος απέκλεισε το μέλος: " + m1);
				Thread.sleep(2000);
				System.out.println("Ο πρόεδρος ολοκληρώνει τον έλεγχο σύγκρουσης συμφερόντων.\n");
				Thread.sleep(2000);
				proedros.Elegxos_Sygkrousis_Symferontwn(a);
				
				System.out.println("Ο πρόεδρος πρέπει να αναθέσει εισηγητή.");
				Thread.sleep(2000);
				
				proedros.anathesi_Eisigisis(m2,a);
				System.out.println("Ο πρόεδρος ανέθεσε την εισήγηση στο μέλος: "+ m2);
				Thread.sleep(2000);
				
				System.out.println("Ο εισηγήτης πρέπει να δημιουργήσει μια εισήγηση.");
				Thread.sleep(2000);
				m2.dimiourgiseEisigisi(a, "Μήπως να συννέλεγε επιστημονικά επιβεβαιωμένα δεδομένα?");

				System.out.println("Ο εισηγητής καλείται να ψηφίσει.");
				Thread.sleep(2000);
				proedros.psifos_Eisigisis(PSIFOS_YPER, a.getEisigisi());
				m3.psifiseGiaEisigisiAitisis(a, PSIFOS_KATA);
				m4.psifiseGiaEisigisiAitisis(a, PSIFOS_KATA);
				
				System.out.println("Ψηφίσανε όλοι και ο πρόεδρος κλείνει την ψηφοφορία.");
				Thread.sleep(2000);
				proedros.Psifoforia(a);
				
				String message1 = (a.getEisigisi().getResult()) ? "Ginetai Apodekth":"Aporriptetai";
				System.out.println(a.getTitle() + " " + message1);
				Thread.sleep(2000);
				
				
				System.out.println("Ο πρόεδρος θα γράψει την απόφαση για την αίτηση.");
				Thread.sleep(2000);
				proedros.syggrafi_Apofasis("Ο ερευνητής δεν συλλέγει πια δεδομένα τα οποία δημιουργούν "
						+ "προβλήματα ηθικής άρα μπορεί να προχωρήσει.", a.getApofasi());
				
				System.out.println("Ο πρόεδρος  θα υπογράψει την απόφαση.");
				Thread.sleep(2000);
				proedros.ypografi_Apofasis(a);
				
				
				System.out.println("Ο πρόεδρος υπέγραψε.\n Η γραμματεία αποστέλλει ενημερωτικό μήνυμα στον ερευνητή.");
				Thread.sleep(2000);
				gr.enimerwse_Ereuniti(a);
				
				Thread.sleep(2000);
				System.out.println("Ο ερευνητής πρέπει να ελέγξει τις αιτήσεις του για να δει την κατάσταση τους\n");
				e.print_Aitiseis();
				Thread.sleep(2000);
				
				
				
			} catch (InterruptedException e) {
				
				e.printStackTrace();
			}

		}
		
		
		
		private static void printScenarioMenu() {
			System.out.println("\n ΕΦΑΡΜΟΓΗ  ΓΙΑ ΤΗΝ ΕΗΔΕ ΤΟΥ ΠΑΜΑΚ\n");
			System.out.println("Πλήκτρο 1: σενάριο αποδοχής της αίτησης από την γραμματεία και όχι από την επιτροπή.\n");
			System.out.println("Πλήκτρο 2: σενάριο απόρριψης της αίτησης από την γραμματεία(ελλιπής).\n ");
			System.out.println("Πλήκτρο 3: σενάριο αποδοχής της αίτησης από την γραμματεία και την επιτροπή.\n");
			System.out.println("Πλήκτρο 4: για την εμφάνιση των Δεδομένων των Καταλόγων.\n");
		}
		
	}


