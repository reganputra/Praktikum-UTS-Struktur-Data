#include <iostream>
#include <string>

using namespace std;

class ContactNode {
public:
    string name;
    string phoneNumber;
    ContactNode* next;

    // Constructor
    ContactNode(const string& _name, const string& _phoneNumber)
        : name(_name), phoneNumber(_phoneNumber), next(nullptr) {}
};

class ContactList {
private:
    ContactNode* head;

public:
    // Constructor
    ContactList() : head(nullptr) {}

    // Destructor untuk membersihkan linked list
    ~ContactList() {
        clearContacts();
    }

    // Fungsi untuk menambahkan node pada awal linked list
    void insertContact(const string& name, const string& phoneNumber) {
        ContactNode* newNode = new ContactNode(name, phoneNumber);
        newNode->next = head;
        head = newNode;
        cout << "Kontak " << name << " dengan nomor " << phoneNumber << " telah ditambahkan." << endl;
    }

    // Fungsi untuk menghapus node dari linked list berdasarkan nama kontak
    void deleteContact(const string& name) {
        ContactNode* current = head;
        ContactNode* prev = nullptr;

        while (current != nullptr && current->name != name) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Kontak " << name << " tidak ditemukan." << endl;
            return;
        }

        if (prev == nullptr) {
            head = current->next;
        } else {
            prev->next = current->next;
        }

        delete current;
        cout << "Kontak " << name << " telah dihapus." << endl;
    }

    // Fungsi untuk mencari node dalam linked list berdasarkan nama kontak
    void searchContact(const string& name) {
        ContactNode* current = head;
        while (current != nullptr) {
            if (current->name == name) {
                cout << "Kontak " << name << " dengan nomor " << current->phoneNumber << " ditemukan." << endl;
                return;
            }
            current = current->next;
        }
        cout << "Kontak " << name << " tidak ditemukan." << endl;
    }

    // Fungsi untuk menampilkan seluruh linked list
    void viewContacts() {
        ContactNode* current = head;
        if (current == nullptr) {
            cout << "Daftar kontak kosong." << endl;
            return;
        }
        cout << "Daftar Kontak:" << endl;
        while (current != nullptr) {
            cout << current->name << ": " << current->phoneNumber << endl;
            current = current->next;
        }
    }

    // Fungsi untuk membersihkan dan menghapus semua node dari linked list
    void clearContacts() {
        ContactNode* current = head;
        ContactNode* nextNode;

        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }

        head = nullptr;
    }
};

int main() {
    ContactList contactList;
    int choice;
    string name, phoneNumber;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Kontak\n";
        cout << "2. Hapus Kontak\n";
        cout << "3. Cari Kontak\n";
        cout << "4. Lihat Kontak\n";
        cout << "5. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan nama kontak: ";
                cin >> name;
                cout << "Masukkan nomor telepon: ";
                cin >> phoneNumber;
                contactList.insertContact(name, phoneNumber);
                break;
            case 2:
                cout << "Masukkan nama kontak yang akan dihapus: ";
                cin >> name;
                contactList.deleteContact(name);
                break;
            case 3:
                cout << "Masukkan nama kontak yang akan dicari: ";
                cin >> name;
                contactList.searchContact(name);
                break;
            case 4:
                contactList.viewContacts();
                break;
            case 5:
                cout << "Program berhenti." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi." << endl;
        }
    } while (choice != 5);

    return 0;
}
