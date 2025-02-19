#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Log mesaj� yap�s�
typedef struct Log {
    char timestamp[20];  // Zaman damgas�
    int severity;        // �nem seviyesi (0: Emergency, 1: Alert, ..., 7: Debug)
    char message[256];   // Log mesaj�
    struct Log* next;    // Bir sonraki log mesaj�na i�aret�i
} Log;

// Ba�l� listenin ba��n� tutacak global de�i�ken
Log* head = NULL;

// Yeni bir log mesaj� ekleme fonksiyonu
void add_log(int severity, const char* message) {
    // Yeni log i�in bellek ay�rma
    Log* new_log = (Log*)malloc(sizeof(Log));
    if (new_log == NULL) {
        printf("Bellek hatas�! Log eklenemedi.\n");
        return;
    }

    // Zaman damgas�n� al
    time_t now = time(NULL);
    strftime(new_log->timestamp, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));

    // Log bilgilerini doldur
    new_log->severity = severity;
    strncpy(new_log->message, message, 255);
    new_log->message[255] = '\0';  // Mesaj�n sonunu garanti alt�na al

    // Yeni log'u bagl� listenin ba��na ekle
    new_log->next = head;
    head = new_log;
}

// T�m loglar� g�r�nt�leme fonksiyonu
void display_logs() {
    Log* current = head;
    if (current == NULL) {
        printf("G�sterilecek log yok.\n");
        return;
    }

    printf("\n--- T�m Loglar ---\n");
    while (current != NULL) {
        printf("[%s] Severity: %d, Mesaj: %s\n", current->timestamp, current->severity, current->message);
        current = current->next;
    }
    printf("------------------\n");
}

// Belle�i temizleme fonksiyonu
void free_logs() {
    Log* current = head;
    Log* next_log;

    while (current != NULL) {
        next_log = current->next;
        free(current);
        current = next_log;
    }

    head = NULL;  // Listenin ba��n� s�f�rla
}

// Ana program
int main() {
    // Rastgele log mesajlar� olu�tur ve ba�l� listeye ekle
    add_log(0, "Sistem acil durumda! Hizmet d���.");
    add_log(3, "Veritaban� ba�lant� hatas�.");
    add_log(5, "Kullan�c� giri�i ba�ar�l�.");
    add_log(7, "Debug: Yeni ba�lant� iste�i al�nd�.");

    // T�m loglar� g�r�nt�le
    display_logs();

    // Belle�i temizle
    free_logs();

    return 0;
}
