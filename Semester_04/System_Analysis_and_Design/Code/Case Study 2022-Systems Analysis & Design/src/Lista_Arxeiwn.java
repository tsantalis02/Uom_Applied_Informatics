import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;

public class Lista_Arxeiwn {
private ArrayList<String> fileList;
	
	
	public Lista_Arxeiwn() {
		fileList = new ArrayList<String>();
	}
	

	public void prosthiki_Arxeiou(String filename) {
		
		this.fileList.add(filename);
	}

	
	public void diagrafi_Arxeiou(String filename) {
		
		this.fileList.remove(filename);
	}
	
	
	
	public String toString() {
		return fileList.toString();
	}
	
	
	public void printData() {
		for(String filename:fileList) {
			System.out.println(filename);
		}
	}
}
