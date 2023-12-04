public class LinkedListStack<T> implements Stack<T> {

    LinkedList<T> list;

    public LinkedListStack() {
        list = new LinkedList<T>();
    }

    @Override
    public boolean isEmpty() {
        return list.isEmpty();
    }

    @Override
    public void push(T newItem) {
        list.addFront(newItem);
    }

    @Override
    public T pop() {
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
