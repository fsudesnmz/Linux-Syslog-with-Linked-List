#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Log mesajý yapýsý
typedef struct Log {
    char timestamp[20];  // Zaman damgasý
    int severity;        // Önem seviyesi (0: Emergency, 1: Alert, ..., 7: Debug)
    char message[256];   // Log mesajý
    struct Log* next;    // Bir sonraki log mesajýna iþaretçi
} Log;

// Baðlý listenin baþýný tutacak global deðiþken
Log* head = NULL;

// Yeni bir log mesajý ekleme fonksiyonu
void add_log(int severity, const char* message) {
    // Yeni log için bellek ayýrma
    Log* new_log = (Log*)malloc(sizeof(Log));
    if (new_log == NULL) {
        printf("Bellek hatasý! Log eklenemedi.\n");
        return;
    }

    // Zaman damgasýný al
    time_t now = time(NULL);
    strftime(new_log->timestamp, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));

    // Log bilgilerini doldur
    new_log->severity = severity;
    strncpy(new_log->message, message, 255);
    new_log->message[255] = '\0';  // Mesajýn sonunu garanti altýna al

    // Yeni log'u baglý listenin baþýna ekle
    new_log->next = head;
    head = new_log;
}

// Tüm loglarý görüntüleme fonksiyonu
void display_logs() {
    Log* current = head;
    if (current == NULL) {
        printf("Gösterilecek log yok.\n");
        return;
    }

    printf("\n--- Tüm Loglar ---\n");
    while (current != NULL) {
        printf("[%s] Severity: %d, Mesaj: %s\n", current->timestamp, current->severity, current->message);
        current = current->next;
    }
    printf("------------------\n");
}

// Belleði temizleme fonksiyonu
void free_logs() {
    Log* current = head;
    Log* next_log;

    while (current != NULL) {
        next_log = current->next;
        free(current);
        current = next_log;
    }

    head = NULL;  // Listenin baþýný sýfýrla
}

// Ana program
int main() {
    // Rastgele log mesajlarý oluþtur ve baðlý listeye ekle
    add_log(0, "Sistem acil durumda! Hizmet dýþý.");
    add_log(3, "Veritabaný baðlantý hatasý.");
    add_log(5, "Kullanýcý giriþi baþarýlý.");
    add_log(7, "Debug: Yeni baðlantý isteði alýndý.");

    // Tüm loglarý görüntüle
    display_logs();

    // Belleði temizle
    free_logs();

    return 0;
}
