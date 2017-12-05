package roundRobin;

import java.util.*;

public class CQueue {
	ArrayList<Process> process = new ArrayList<Process>();
	
	int front = 0;
	int end = 0; 
	int queueSize = 1; // So there is a room for the front element to get in 
	
	public CQueue() {}
	
	//Add and Kill a process
	public void addProcess(Process p) {
		process.add(p);
		
		end++;
		queueSize = process.size();
	}
	public void killProcess(Process p) {
		process.remove(p);
		queueSize--;
	}
	
	//Show processes
	public void showProcess() {
		for(int j = 0; j < process.size(); j++) {
			if(j == 0) System.out.println("Next process: " + process.get(j).ID);
			else System.out.println("Process: " + process.get(j).ID);
			
		}
	}
	
	//Iterate Process ==> Circular Feature
	public void itrProcess() {
		if ( (front == end) && ((front & end) == 0) ) {
			return;
		} else {
			process.add(process.get(front));
			process.remove(process.get(front));
		}
	}
}
