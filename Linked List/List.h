
template<typename T>
class List {
private:
    template<typename N>
    class Node {
    public:
        N data;
        Node *pNext;
        explicit Node(N data = N(), Node *pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int size_;
public:
    Node<T> *head;

    List();
    ~List();
    void push_back(T data);
    int size() { return size_; }
    T &operator[](int index);
    void pop_front();
    void clear();
    void push_front(T data);
    void insert(T data, int index);
    void remove(int index);
    void pop_back();
};
