
template <typename T>
class List {
private:
    template<typename N>
    class Node {
    public:
        N data;
        Node *prev, *next;
        Node() { prev = next = nullptr; }
    };
    Node<T> *Head, *Tail;
    int size_;
public:
    List();
    List(const List& list);
    ~List();

    int size();

    void push_back(T data);
    void push_front(T data);
    void pop_back();
    void pop_front();
    T& get_back();
    T& get_front();
};
