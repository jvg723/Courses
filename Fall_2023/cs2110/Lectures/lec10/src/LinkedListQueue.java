public class LinkedListQueue<T> implements Queue<T> {

    LinkedList<T> list;

    public LinkedListQueue() {
        list = new LinkedList<T>();
    }

    @Override
    public boolean isEmpty() {
        return list.isEmpty();
    }

    @Override
    public void enqueue(T newItem) {
        list.addBack(newItem);
    }

    @Override
    public T dequeue() {
        if (list.isEmpty()) {
            throw new EmptyException();
        }
        return list.remove(1);
    }

    @Override
    public T peek() {
        if (list.isEmpty()) {
            throw new EmptyException();
        }
        return list.get(1);
    }
}
