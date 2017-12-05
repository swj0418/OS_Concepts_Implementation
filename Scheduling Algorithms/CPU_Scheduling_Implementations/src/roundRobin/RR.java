package roundRobin;
import java.util.*;

public class RR {
	static Process[] process = new Process[10]; //Initializing 10 Processes ==> Don't need this anymore.
	static CQueue Q = new CQueue();
	static ArrayList<Process> fin_process = new ArrayList<Process>();
	static int choice = 0;
	static int bursttime = 0;
	static long inter_t = 0;
	static long turnaround_os = 0;
	
	public static void main(String[] ar)
	{
		Scanner in = new Scanner(System.in);
		System.out.println("1. SJF 2. Random 3. RR");
		choice = in.nextInt();
		
		if(choice == 3) {
			for(int i = 1; i < 11; i++) { // i < 11 means that I am initializing 10 Processes with each ID given as i.
				Q.addProcess(new Process(i));
			}
			System.out.print("Input a bursttime : "); bursttime = in.nextInt();
			
			inter_t = System.currentTimeMillis();
			Iterator itr= Q.process.iterator();
			while(itr.hasNext()) {
				if(Q.process.get(0).completion == false) {
					System.out.println("Process " + Q.process.get(0).ID + " Running");
					Q.process.get(0).on = true;
					Q.process.get(0).job_2();
					
				}
				else if(Q.process.get(0).completion == true) {
					Q.process.get(0).on = false;
					System.out.println("============ Process " + Q.process.get(0).ID + "==============");
					System.out.println("Completion : " + Q.process.get(0).completion + " " +
					"Time taken : " + Q.process.get(0).timetaken + " " + "Finished Result : " + Q.process.get(0).fin_res + " " + 
					"Context : " + Q.process.get(0).context + "\t" + "Times entered : " + Q.process.get(0).times_entered);
					
					turnaround_os = System.currentTimeMillis() - inter_t;
					Q.process.get(0).turnaround = turnaround_os;
					System.out.println("Turnaround time for the process : " + turnaround_os);
					turnaround_os = 0L;

					Q.process.get(0).waiting_t = (Q.process.get(0).turnaround - Q.process.get(0).timetaken) -
							(Q.process.get(0).timetaken % bursttime);
					
					fin_process.add(Q.process.get(0));
					
					Q.killProcess(Q.process.get(0));
				}
			}
			
			float total_burst_time = 0;
			float total_itrs = 0;
			
			for(int i = 0; i < fin_process.size(); i++) {
				total_burst_time += fin_process.get(i).timetaken;
				total_itrs += fin_process.get(i).times_entered;
			}
			
			System.out.println("All processes completed after : " + total_burst_time + " msecs" + " total iterations : "
					+ total_itrs);
			
			for(int i = 0; i < fin_process.size(); i++) {
				System.out.println("============ Process " + fin_process.get(i).ID + "==============");
				System.out.println("Completion : " + fin_process.get(i).completion + " " +
				"Time taken : " + fin_process.get(i).timetaken + " " + "Finished Result : " + fin_process.get(i).fin_res + " " + 
				"Context : " + fin_process.get(i).context + "\t" + "Times entered : " + fin_process.get(i).times_entered + "\n" +
				"Waiting Time : " + fin_process.get(i).waiting_t + " Turnaround : " + fin_process.get(i).turnaround);
			}
		}
		else if (choice == 1) {
			
			for(int i = 1; i < 11; i++) {
				Q.addProcess(new Process(i));
			}
				bursttime = 1000000000;
				
				inter_t = System.currentTimeMillis();
				Iterator itr = Q.process.iterator();
				while(itr.hasNext()) {
					if(Q.process.get(0).completion == false) {
						System.out.println("Process " + Q.process.get(0).ID + " Running");
						long t = System.currentTimeMillis();
						Q.process.get(0).on = true;
						Q.process.get(0).job_2();
					}
					else if (Q.process.get(0).completion == true) {
						Q.process.get(0).on = false;
						
						System.out.println("============ Process " + Q.process.get(0).ID + "==============");
						System.out.println("Completion : " + Q.process.get(0).completion + " " +
						"Time taken : " + Q.process.get(0).timetaken + " " + "Finished Result : " + Q.process.get(0).fin_res + " " + 
						"Context : " + Q.process.get(0).context + "\t" + "Times entered : " + Q.process.get(0).times_entered);
						
						turnaround_os = System.currentTimeMillis() - inter_t;
						Q.process.get(0).turnaround = turnaround_os;
						System.out.println("Turnaround time for the process : " + turnaround_os);
						turnaround_os = 0L;

						Q.process.get(0).waiting_t = (Q.process.get(0).turnaround - Q.process.get(0).timetaken);
						
						fin_process.add(Q.process.get(0));
						Q.killProcess(Q.process.get(0));
					}
				}
				
				float total_burst_time = 0;
				float total_itrs = 0;
				
				for(int i = 0; i < fin_process.size(); i++) {
					total_burst_time += fin_process.get(i).timetaken;
					total_itrs += fin_process.get(i).times_entered;
				}
				
				System.out.println("All processes completed after : " + total_burst_time + " msecs" + " total iterations : "
						+ total_itrs);
				
				
				for(int i = 0; i < fin_process.size(); i++) {
					System.out.println("============ Process " + fin_process.get(i).ID + "==============");
					System.out.println("Completion : " + fin_process.get(i).completion + " " +
					"Time taken : " + fin_process.get(i).timetaken + " " + "Finished Result : " + fin_process.get(i).fin_res + " " + 
					"Context : " + fin_process.get(i).context + "\t" + "Times entered : " + fin_process.get(i).times_entered  + "\n" +
					"Waiting Time : " + fin_process.get(i).waiting_t + " Turnaround : " + fin_process.get(i).turnaround);
				}
			}
		}

	public static void interrupt(Process p, Long CPU_USAGE_TIME) {
		
		if(CPU_USAGE_TIME >= bursttime || p.completion == true) {
			p.on = false;
			Q.itrProcess();
		} else if(bursttime == 0 || p.completion == true) {
			p.on = false;
			Q.itrProcess();
		}
	}
}