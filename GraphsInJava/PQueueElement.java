
public class PQueueElement implements Comparable<PQueueElement>{
	int minDist_key;
	int vertex;
	
	PQueueElement(int key, int val)
	{
		minDist_key=key;
		vertex=val;
	}
	
	@Override
	public int compareTo(PQueueElement other) {
		// TODO Auto-generated method stub
		return Integer.compare(this.minDist_key, (int) other.minDist_key);
	}
}
