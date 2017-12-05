package main;
import java.util.*;

public class CircularQueue {
	ArrayList<Process> CQueue = new ArrayList<Process>();
	Process tmp_p;
	static int initial_size = 10;
	int front = 0;
	int end = 0;
	
	@SuppressWarnings("rawtypes")
	HashMap<String, Process> QueueMap = new HashMap<String, Process>();
	
	CircularQueue() {}
	CircularQueue(Process p) {
		CQueue.add(p);
	}
	public void addProcess(Process p) {
		if(end < initial_size) {
			CQueue.add(p);
			QueueMap.put(String.valueOf(p.ID), p);
			end++;
		} else if (isfull()) {
			tmp_p = CQueue.get(front);
			CQueue.remove(front);
			CQueue.add(p);
		}
	}
	public void itrProcess() {
			tmp_p = CQueue.get(front);
			CQueue.remove(front);
			CQueue.add(tmp_p);
	}
	public boolean isempty() {
		if(front == end) return true;
		else return false;
	}
	public boolean isfull () {
		if(initial_size == end || initial_size < end) {
			return true;
		} else {
			return false;
		}
	}
	public void destroyProcess(Process p) {
		CQueue.remove(p);
	}
	
	// To show processes in the Queue
	public void showProcesses() {
		int i = 0;
		Iterator itr = CQueue.iterator();
		
		System.out.println("=====Current Processes=====");
		while(itr.hasNext() == true) {
			System.out.println("Process ID : " + CQueue.get(i).ID + "  Process Completion : " + CQueue.get(i).Completion);
			i++;
			if(i == CQueue.size()) break;
		}
	}
	
	public Process get(int i) {
		return CQueue.get(i);
	}
	
	public static void main(String[] ar) {
		CircularQueue Q = new CircularQueue();
	}

}