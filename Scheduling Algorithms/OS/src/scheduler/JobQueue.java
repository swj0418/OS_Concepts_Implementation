package scheduler;
import java.util.ArrayList;

public class JobQueue extends ArrayList {
	public NewQueue nq = new NewQueue();
	public ReadyQueue rq = new ReadyQueue();
	public WaitingQueue wq = new WaitingQueue();
	public TerminatedQueue tq = new TerminatedQueue();
	
	public JobQueue() {
		
	}
}
