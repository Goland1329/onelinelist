#include <iostream>

using namespace std;


template<typename T>
struct Node {
    T data;
    Node *next;

    Node(T x) {
        data = x;
        Node *next = NULL;
    }
};


template<typename T>
class List {
    Node<T> *head;
public:
    ~List() {
        Node<T> *ptr = head;
        head = NULL;
        while (ptr) {
            Node<T> *tmp = ptr;
            ptr = ptr->next;
            delete (tmp);
        }
    }

    List(Node<T> *h = NULL) {
        head = h;
    }

    bool Isempty() {
        if (head == NULL) {

            return true;
        } else {
            return false;
        }
    }

    void Pushfront(T x) {
        Node<T> *a = new Node<T>(x);
        a->next = head;
        head = a;
    }

    void Pushback(T x) {
        Node<T> *a = new Node<T>(x);
        if (Isempty()) {
            head = a;
            head->next = NULL;
        } else {
            Node<T> *b = head;
            while (b->next != NULL) {
                b = b->next;
            }
            b->next = a;
            a->next = NULL;
        }


    }

    void Popfront() {
        if (!Isempty()) {
            Node<T> *c = head;
            head = head->next;
            delete (c);
        } else {
            cout << "ERROR\n";
        }

    }

    void Popback() {
        if (!Isempty()) {
            Node<T> *x = head;
            Node<T> *tmp;
            while (x->next->next != NULL) {
                x = x->next;
            }
            delete (x->next);
            x->next = NULL;

        }
    }

    void Pushbefore(T x, Node<T> *y) {
        Node<T> *f = new Node<T>;
        if (head->next == NULL) {
            if (head == y) {
                f->next = head;
                f->data = x;
                head = f;
            }
        } else {
            Node<T> *k = head;
            while (k->next != y) {
                k = k->next;
            }
            f->next = y;
            f->data = x;
            k->next = f;
        }
    }

    void Poppointer(Node<T> *x) {
        if (!Isempty()) {
            if (head->next == NULL) {
                if (x == head) {
                    Node<T> *y = head;
                    head = NULL;
                    delete (y);
                }
            } else {
                Node<T> *k = head;
                while (k->next != x) {
                    k = k->next;
                }
                Node<T> *g = k->next;
                k->next->next = g;
                delete (g);
            }
        }
    }
    Node<T>* Searchdata(T x) {
        if (!Isempty()) {
            Node<T> *b = head;
            while (b->data != x && b != NULL) {
                b = b->next;
            }
            if (b->data==x){
                cout<<"yes"<<endl;
                return b;
            }
            else
                cout<<"no"<<endl;
        }
    }

    void Deletedata(T x) {
        if (!Isempty()) {
            if (head->next == NULL) {
                if (head->data == x) {
                    Node<T> *tmp = head;
                    head = NULL;
                    delete (tmp);
                }
            } else {
                Node<T> *b = head;
                if (head->data != x) {

                    while (b->next->data != x) {
                        b = b->next;
                    }
                    Node<T> *a = b->next;
                    b->next = b->next->next;
                    delete (a);
                } else {
                    Node<T> *c = head;
                    head = head->next;
                    delete (c);
                }
            }
        }
    }
    template<typename Type>
    friend ostream &operator<<(ostream &os, const List<Type> &a) {
        Node<Type> *ptr = a.head;
        while (ptr != NULL) {
            os << ptr->data << ' ';
            ptr = ptr->next;
        }
        os << endl;
        return os;
    }

    List operator+(const List<T> &b) {
        List<T> L;
        Node<T> *d = head;
        while (d != NULL) {
            L.Pushback(d->data);
            d = d->next;
        }
        d = b.head;
        while (d != NULL) {
            L.Pushback(d->data);
            d = d->next;
        }
        return L;
    }
};


int main() {

    List<int> s;
    cout<<"Добавление в конец-Pushback x"<<endl<<"Добавление в начало-Pushfront x"<<endl<<"Удаление из начала - Popfront x"<<endl;
    cout<<"Удаление из конца - Popfront x"<<endl<<"Найди элемент - Searchdata x"<<endl<<"Удалить элемент - Deletedata x"<<"Вывести список - print"<<endl;
    while (true) {
        string a;
        cin >> a;
        if (a == "Pushback") {
            cin >> a;
            s.Pushback(stoi(a));
            cout<<s;
        }
        if (a == "Pushfront") {
            cin >> a;
            s.Pushfront(stoi(a));
            cout<<s;
        }
        if (a == "Popfront") {
            s.Popfront();
            cout<<s;
        }

        if (a == "Popback") {
            s.Popback();
            cout<<s;
        }
        if (a=="Search data"){
            cin>>a;
            s.Searchdata(stoi(a));
            cout<<s;
        }
        if (a=="Deletedata") {
            cin >> a;
            s.Deletedata(stoi(a));
            cout<<s;
        }
        if (a=="Print")
            cout<<s;
    }


        return 0;
    }
