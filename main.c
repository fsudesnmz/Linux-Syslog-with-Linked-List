#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Log mesajı yapısı
typedef struct Log {
    char timestamp[20];  // Zaman damgası
    int severity;        // Önem seviyesi (0: Emergency, 1: Alert, ..., 7: Debug)
    char message[256];   // Log mesajı
    struct Log* next;    // Bir sonraki log mesajına işaretçi
} Log;

// Bağlı listenin başını tutacak global değişken
Log* head = NULL;

// Yeni bir log mesajı ekleme fonksiyonu
void add_log(int severity, const char* message) {
    // Yeni log için bellek ayırma
    Log* new_log = (Log*)malloc(sizeof(Log));
    if (new_log == NULL) {
        printf("Bellek hatasý! Log eklenemedi.\n");
        return;
    }

    // Zaman damgasını al
    time_t now = time(NULL);
    strftime(new_log->timestamp, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));

    // Log bilgilerini doldur
    new_log->severity = severity;
    strncpy(new_log->message, message, 255);
    new_log->message[255] = '\0';  // Mesajın sonunu garanti altına al

    // Yeni log'u baglı listenin başına ekle
    new_log->next = head;
    head = new_log;
}

// Tüm logları görüntüleme fonksiyonu
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

// Belleği temizleme fonksiyonu
void free_logs() {
    Log* current = head;
    Log* next_log;

    while (current != NULL) {
        next_log = current->next;
        free(current);
        current = next_log;
    }

    head = NULL;  // Listenin başını sıfırla
}

// Ana program
int main() {
    // Rastgele log mesajları oluştur ve bağlı listeye ekle
    add_log(0, "Sistem acil durumda! Hizmet disi.");
    add_log(3, "Veritabani baglanti hatasi.");
    add_log(5, "Kullanici girisi basarili.");
    add_log(7, "Debug: Yeni baglanti istegi alindi.");

    // Tüm logları görüntüle
    display_logs();

    // Belleği temizle
    free_logs();

    return 0;
}
