# Log Yönetim Sistemi

Bu proje, basit bir log yönetim sistemi örneğidir. C programlama dili kullanılarak geliştirilen bu sistem, log mesajlarını **tek yönlü bağlı liste (singly linked list)** yapısı kullanarak kaydeder ve görüntüler. Log mesajları, zaman damgası, önem seviyesi ve mesaj içeriği gibi bilgileri içerir.

## Özellikler

- **Log Ekleme**: Yeni log mesajları ekleyebilirsiniz. Her log mesajı, zaman damgası, önem seviyesi ve mesaj içeriği ile birlikte kaydedilir.
- **Log Görüntüleme**: Kaydedilen tüm log mesajlarını görüntüleyebilirsiniz. Loglar, zaman damgası, önem seviyesi ve mesaj içeriği ile birlikte listelenir.
- **Bellek Yönetimi**: Program sonlandığında, bağlı liste yapısı kullanılarak ayrılan bellek otomatik olarak temizlenir.

## Bağlı Liste Türü

Bu programda, log mesajlarını saklamak için **tek yönlü bağlı liste (singly linked list)** yapısı kullanılmıştır. Bağlı listenin özellikleri şunlardır:
- Her bir log mesajı, bir `Log` düğümü (node) olarak temsil edilir.
- Her düğüm, bir sonraki düğüme işaret eden bir `next` işaretçisi içerir.
- Yeni log mesajları, bağlı listenin **başına (head)** eklenir. Bu, ekleme işlemini O(1) zaman karmaşıklığında gerçekleştirir.
- Loglar görüntülenirken, baştan sona doğru tüm düğümler gezilir.

## Kullanım

1. **Log Ekleme**: `add_log` fonksiyonu kullanılarak yeni log mesajları eklenebilir. Örnek kullanım:
   ```c
   add_log(3, "Veritabanı bağlantı hatası.");
   ```

2. **Log Görüntüleme**: `display_logs` fonksiyonu kullanılarak kaydedilen tüm log mesajları görüntülenebilir. Örnek çıktı:
   ```
   --- Tüm Loglar ---
   [2023-10-05 14:30:45] Severity: 3, Mesaj: Veritabanı bağlantı hatası.
   [2023-10-05 14:30:40] Severity: 0, Mesaj: Sistem acil durumda! Hizmet dışı.
   ------------------
   ```

3. **Bellek Temizleme**: `free_logs` fonksiyonu kullanılarak bağlı liste yapısı temizlenir ve bellek sızıntısı önlenir.

## Önem Seviyeleri

Log mesajları, aşağıdaki önem seviyelerine sahip olabilir:

- `0`: Emergency (Acil)
- `1`: Alert (Uyarı)
- `2`: Critical (Kritik)
- `3`: Error (Hata)
- `4`: Warning (Uyarı)
- `5`: Notice (Bildirim)
- `6`: Informational (Bilgilendirme)
- `7`: Debug (Hata Ayıklama)

## Kurulum

1. Bu projeyi bilgisayarınıza klonlayın:
   ```bash
   git clone https://github.com/kullanici_adi/log-yonetim-sistemi.git
   ```

2. Proje dizinine gidin:
   ```bash
   cd log-yonetim-sistemi
   ```

3. Programı derleyin ve çalıştırın:
   ```bash
   gcc -o log_yonetim log_yonetim.c
   ./log_yonetim
   ```

## Katkıda Bulunma

Bu proje açık kaynaklıdır ve katkılarınızı bekliyoruz. Katkıda bulunmak için lütfen bir "fork" oluşturun ve değişikliklerinizi bir "pull request" ile gönderin.

## Lisans

Bu proje MIT Lisansı altında lisanslanmıştır. Daha fazla bilgi için `LICENSE` dosyasına bakın.

---
