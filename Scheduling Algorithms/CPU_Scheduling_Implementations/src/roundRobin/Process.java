package roundRobin;

import java.util.*;
public class Process extends RR{
	public int ID;
	public boolean on = false;
	public boolean completion = false; //Will be used to check whether the process is complete or not.
	public long timetaken = 0L;
	public long turnaround = 0L;
	public long waiting_t = 0L;
	public int context = 0;
	public double fin_res = 0;
	public int times_entered = 0;
	
	public long jobtime = 0;
	
	Process(int ID) {
		this.ID = ID;
		this.on = false;
		this.completion = false;
		this.timetaken = 0L;
		this.context = 0;
		this.fin_res = 0;
		this.jobtime = 0;
		this.times_entered = 0;
	}
	public Process() {
	}
	
	public void job_1() {
		double res = fin_res;
		long t_1 = System.currentTimeMillis();
		
		if(on == true && completion == false) {
			for(int i = context; i < ID * 100000000; i++) {
				long t_m = System.currentTimeMillis();
				if(((t_m - t_1) == 100 || (t_m - t_1) > 100) && (context != ID * 100000000)) {
					context = i;
					fin_res = res;
					timetaken += (t_m - t_1);
					on = false;
					System.out.println("Switching");
					break;
				} else if((t_m - t_1) < 100) {
					res += i;
				}
			}
			if(context - 1 == ID * 100000000) {
				completion = true;
				on = false;
			}
		}
		else if(completion == true) {
			System.out.println("Completed Process");
		}
	}
	
	public void job_2() {
		long tmp_time = System.currentTimeMillis(); //To check how much spent in the method.
		jobtime = 0; // Initialize every time a process enters its job.
		double calc = fin_res;
		int ran = (int)(Math.random() * 10) + 1;
		int target = (int) ran * 9000000;
		//int target = (-(ID - 11)) * 100000000;
		//int target = ID * 100000000;
		times_entered++;
		for (int i = context; i < target + 1; i++) {
			jobtime = System.currentTimeMillis();
			interrupt(this, jobtime - tmp_time);
			
			if(i == target || context == target) {
				completion = true;
				interrupt(this, jobtime - tmp_time);
			}
			if(on == true && completion == false) {
				calc += i;
				jobtime = System.currentTimeMillis();
			}
			if(on == false || completion == true) {
				context = i;
				jobtime = System.currentTimeMillis();
				timetaken += (jobtime - tmp_time);
				fin_res = calc;
				break;
			}
		}
	}
}
