
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
    void push_back(T data);  // adds element in the end of list
    int size() { return size_; }  // returns size of the list
    T &operator[](int index);  // [] operator overloading
    void pop_front();  // deletes first element of the list
    void clear();  // clearing of the list
    void push_front(T data);  // adds element in beginning of the list
    void insert(T data, int index);  // inserts one element at defined index
    void remove(int index);  // removes element at index
    void pop_back();  // removes last element
};
