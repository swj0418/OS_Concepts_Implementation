package main;

import java.util.*;
import java.time.*;

public class RoundRobinImpl implements Runnable{
	static CircularQueue Q = new CircularQueue();
	static Long TQ = 0L; //Time Quantum or Time Slice
	
	public static void main(String[] ar) {
		Scanner in = new Scanner(System.in);
		
		System.out.print("Insert a time quantum : "); TQ = in.nextLong();
		
		Process p1 = new Process(1, "Default");
		Process p2 = new Process(2, "Default");
		Process p3 = new Process(3, "Default");
		Process p4 = new Process(4, "Default");
		Process p5 = new Process(5, "Default");
		Process p6 = new Process(6, "Default");
		Process p7 = new Process(7, "Default");
		Process p8 = new Process(8, "Default");
		Process p9 = new Process(9, "Default");
		Process p10 = new Process(10, "Default");
		Q.addProcess(p1);
		Q.addProcess(p2);
		Q.addProcess(p3);
		Q.addProcess(p4);
		Q.addProcess(p5);
		Q.addProcess(p6);
		Q.addProcess(p7);
		Q.addProcess(p8);
		Q.addProcess(p9);
		Q.addProcess(p10);

		Q.showProcesses();
		
		new Thread(new RoundRobinImpl()).start();
	}
	@Override
	public void run() {
		Iterator itr = Q.CQueue.iterator();
		int i = 0;
		while(i < Q.initial_size) {
			Q.CQueue.get(i).DefaultJob(Q.CQueue.get(i));
			//System.out.println("Processing process..." + Q.CQueue.get(i).ID);
			i++;
		}
		
	}
}
