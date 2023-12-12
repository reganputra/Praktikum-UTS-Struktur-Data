#include <iostream>
#define size 6
using namespace std;

struct gudang
{
    string namaBarang;
    string namaPenitip;
};

int front = 0;
int rear = 0;
gudang arr[size];

void enqueue()
{
    string namaBarang, namaPenitip;
    if ((rear + 1) % size == front)
    {
        cout << "Loker penuh!";
    }
    else
    {
        cout << "Masukan Nama Barang\t:";
        cin.ignore();
        getline(cin, namaBarang);
        cout << "Masukan Nama Penitip\t:";
        getline(cin, namaPenitip);

        arr[rear].namaBarang = namaBarang;
        arr[rear].namaPenitip = namaPenitip;

        rear = (rear + 1) % size;
    }
}

void dequeue()
{
    string namaBarang, namaPenitip;
    if (rear == front)
    {
        cout << "Loker masih kosong";
    }
    else
    {
        string namaBarang = arr[front].namaBarang;
        string namaPenitip = arr[front].namaPenitip;

        cout << "Barang yang diambil" << endl;
        cout << "Nama Barang:" << namaBarang << endl;
        cout << "Nama Penitip:" << namaPenitip << endl;

        front = (front + 1) % size;
    }
}

void display()
{
    if (front == rear)
    {
        cout << "Loker masih kosong";
    }
    else
    {
        int i = front;
        cout << "Barang didalam loker:" << endl;
        for (int i = front; i != rear; i = (i + 1) % size)
        {
            cout << "------------------" << endl;
            cout << "Nama Barang\t:" << arr[i].namaBarang << endl;
            cout << "Nama Penitip\t:" << arr[i].namaPenitip << endl;
        }

        cout << arr[rear].namaBarang << "-" << arr[rear].namaPenitip << endl;
    }
}

int main()
{
    int choice;

    while (1)
    {
        system("cls");
        cout << "Penitipan Barang" << endl;
        cout << "------------------" << endl;
        cout << "1.Titip Barang" << endl;
        cout << "------------------" << endl;
        cout << "2. Ambil barang" << endl;
        cout << "------------------" << endl;
        cout << "3.tampilkan barnag" << endl;
        cout << "------------------" << endl;
        cout << "4.Tutup" << endl;
        cout << "------------------" << endl;
        cout << "Pilih Menu" << endl;
        cout << "------------------" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            enqueue();
            system("pause");
            break;

        case 2:
            dequeue();
            system("pause");
            break;

        case 3:
            display();
            system("pause");
            break;

        case 4:
            exit(0);

        default:
            cout << "Pilihan tidak valid";
        }
    }

    return 0;
}
