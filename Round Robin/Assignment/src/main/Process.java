package main;

public class Process{
	public int ID = 0;
	public static Boolean Completion = false;
	Double[] DefaultResult = new Double[10];
	Integer[] DefaultResult_2 = new Integer[10];
	
	public Process(int ID) {
		this.ID = ID;
		for(int i = 0; i < 10; i++) {
			DefaultResult[i] = (double) ID;
			DefaultResult_2[i] = ID;
		}
	}
	public Process() {
		
	}
	
	public Process(int ID, String worktype) {
		this.ID = ID;
		for(int i = 0; i < 10; i++) {
			DefaultResult[i] = (double) ID;
			DefaultResult_2[i] = ID;
		}
	}
	
	//Default Job
	public Double DefaultJob(Process p) {
		Double value = 0.0d;
		int value_2 = 0;
		
		for(Double i = p.DefaultResult[p.ID]; i < p.ID + 1.0d; i += 0.000001) {
			value += i;
		}
		//Temporary Context Saving for a Context Switching
		DefaultResult[p.ID] = value;
		
		System.out.print("Processing process..." + p.ID);
		
		
		
		Completion = true;
		System.out.println("   Completion : " + p.Completion + " " + p.DefaultResult[p.ID]);
		return value;
	}

}
