#include <iostream>

#define MAX_EMPLOYEES 100
#define MAX_JOBDESKS 5

// Struktur data 
struct Employee {
    int employeeId;
    std::string name;
    double salary;
};

class EmployeeManager {
private:
    Employee employees[MAX_EMPLOYEES];
    int employeeCount;

public:
    // Constructor
    EmployeeManager() : employeeCount(0) {}

    void addEmployee(int id, const std::string& name, double salary) {
        if (employeeCount < MAX_EMPLOYEES) {
            employees[employeeCount].employeeId = id;
            employees[employeeCount].name = name;
            employees[employeeCount].salary = salary;
            employeeCount++;
            std::cout << "Karyawan berhasil ditambahkan." << std::endl;
        } else {
            std::cout << "Batas maksimum karyawan telah tercapai." << std::endl;
        }
    }

    void displayEmployees() const {
        std::cout << "Daftar Karyawan:" << std::endl;
        for (int i = 0; i < employeeCount; i++) {
            std::cout << "ID: " << employees[i].employeeId << ", Nama: " << employees[i].name << ", Gaji: " << employees[i].salary << std::endl;
        }
    }

    void sortEmployeesBySalary() {
        for (int i = 0; i < employeeCount - 1; i++) {
            for (int j = 0; j < employeeCount - i - 1; j++) {
                if (employees[j].salary > employees[j + 1].salary) {
                    Employee temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
        std::cout << "Sorting karyawan berdasarkan gaji selesai." << std::endl;
    }
};

struct JobDesk {
    int employeeId;
    std::string task;
};

class QueueManager {
private:
    JobDesk jobQueue[MAX_JOBDESKS];
    int front, rear;

public:
    QueueManager() : front(-1), rear(-1) {}

    void enqueueJob(int employeeId, const std::string& task) {
        if (rear == MAX_JOBDESKS - 1) {
            std::cout << "Antrian jobdesk penuh." << std::endl;
        } else {
            if (front == -1) {
                front = 0;
            }
            rear++;
            jobQueue[rear].employeeId = employeeId;
            jobQueue[rear].task = task;
            std::cout << "Jobdesk berhasil ditambahkan ke antrian." << std::endl;
        }
    }

    void dequeueJob() {
        if (front == -1) {
            std::cout << "Antrian jobdesk kosong." << std::endl;
        } else {
            std::cout << "Jobdesk '" << jobQueue[front].task << "' untuk karyawan ID " << jobQueue[front].employeeId << " telah dilaksanakan." << std::endl;
            if (front == rear) {
                front = rear = -1;
            } else {
                front++;
            }
        }
    }

    void displayJobQueue() const {
        if (front == -1) {
            std::cout << "Antrian jobdesk kosong." << std::endl;
        } else {
            std::cout << "Antrian Jobdesk:" << std::endl;
            for (int i = front; i <= rear; i++) {
                std::cout << "Karyawan ID " << jobQueue[i].employeeId << ": " << jobQueue[i].task << std::endl;
            }
        }
    }

    void destroyAllJobDesk() {
        this->front = this->rear = -1; 
        std::cout << "Semua jobdesk berhasil dihapus dari antrian." << std::endl;
    }
};

int main() {
    EmployeeManager employeeManager;
    QueueManager queueManager;

    std::cout << "\nFinal Project Kelompok 8\n" << std::endl;
    std::cout << "\n";
    std::cout << "Anggota Kelompok : " << std::endl;
    std::cout << "AYODYA FADE EDFIRA (22081010120)\nBRYAN ANANTHA MANGGALA PRANAJA HARTONO (22081010164)\nMUHAMMAD NUR RAZAQI MAULANA (22081010242)\nFIRZANNABEEL AQILA RAFID (22081010285)" << std::endl;
    std::cout << "\n";

    int choice;
    do {
        // Menampilkan menu
        std::cout << "\n=== Menu Manajemen Perusahaan ===" << std::endl;
        std::cout << "1. Tambah Karyawan" << std::endl;
        std::cout << "2. Tampilkan Karyawan" << std::endl;
        std::cout << "3. Tambah Jobdesk" << std::endl;
        std::cout << "4. Laksanakan Jobdesk" << std::endl;
        std::cout << "5. Tampilkan Jobdesk" << std::endl;
        std::cout << "6. Sorting Gaji Karyawan" << std::endl;
        std::cout << "7. Hapus Semua Jobdesk" << std::endl; 
        std::cout << "0. Keluar" << std::endl;
        std::cout << "Pilih menu (0-7): ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                std::string name;
                double salary;
                std::cout << "Masukkan ID Karyawan: ";
                std::cin >> id;
                std::cout << "Masukkan Nama Karyawan: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Masukkan Gaji Karyawan: ";
                std::cin >> salary;
                employeeManager.addEmployee(id, name, salary);
                break;
            }
            case 2:
                employeeManager.displayEmployees();
                break;
            case 3: {
                int id;
                std::string task;
                std::cout << "Masukkan ID Karyawan untuk Jobdesk: ";
                std::cin >> id;
                std::cout << "Masukkan Deskripsi Jobdesk: ";
                std::cin.ignore();
                std::getline(std::cin, task);
                queueManager.enqueueJob(id, task);
                break;
            }
            case 4:
                queueManager.dequeueJob();
                break;
            case 5:
                queueManager.displayJobQueue();
                break;
            case 6:
                employeeManager.sortEmployeesBySalary();
                break;
            case 7:
                queueManager.destroyAllJobDesk();
                break;
            case 0:
                std::cout << "Program selesai." << std::endl;
                break;
            default:
                std::cout << "Pilihan tidak valid. Silakan coba lagi." << std::endl;
        }

    } while (choice != 0);

    return 0;
}
