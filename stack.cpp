#include <iostream>
using namespace std;

#define SIZE 5 

struct Stack
{
    int arr[SIZE];
    int top;

    Stack()
    {
        top = -1;
    }

    void push(int elem)
    {
        if (top == SIZE - 1)
        {
            cout << "Stack penuh, tidak dapat menambahkan elemen." << endl;
            return;
        }
        arr[++top] = elem;
        cout << "Elemen " << elem << " berhasil di-push ke dalam stack." << endl;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack kosong, tidak ada elemen untuk di-pop." << endl;
            return;
        }
        int poppedElem = arr[top--];
        cout << "Elemen " << poppedElem << " berhasil di-pop dari stack." << endl;
    }

    void displayTop()
    {
        if (top != -1)
        {
            cout << "Top element: " << arr[top] << endl;
        }
        else
        {
            cout << "Stack kosong, tidak ada elemen untuk ditampilkan." << endl;
        }
    }

    void displayStack()
    {
        if (top != -1)
        {
            cout << "Isi stack saat ini:" << endl;
            for (int i = 0; i <= top; ++i)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "Stack kosong, tidak ada elemen untuk ditampilkan." << endl;
        }
    }
};

int main()
{
    Stack myStack;
    int choice;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Top\n";
        cout << "3. Pop\n";
        cout << "4. Tampilkan Stack\n"; 
        cout << "5. Keluar\n";
        cout << "Pilih operasi yang diinginkan: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int elem;
            cout << "Masukkan elemen yang ingin di-push: ";
            cin >> elem;
            myStack.push(elem);
            break;
        }

        case 2:
            myStack.displayTop();
            break;

        case 3:
            myStack.pop();
            break;

        case 4:
            myStack.displayStack(); 
            break;

        case 5:
            break;

        default:
            cout << "Pilihan tidak valid." << endl;
        }

    } while (choice != 5);

    return 0;
}
