# Bağlı Liste ile Syslog Uygulaması

Bu proje, **syslog** mekanizmasına benzer şekilde çalışan basit bir log yönetim sistemi örneğidir. C programlama dili kullanılarak geliştirilen bu sistem, log mesajlarını **tek yönlü bağlı liste (singly linked list)** yapısı kullanarak kaydeder ve görüntüler. Syslog, Unix ve Linux sistemlerinde yaygın olarak kullanılan bir log kayıt mekanizmasıdır ve bu proje, syslog'un temel özelliklerini basit bir şekilde taklit eder.

## Syslog Nedir?

**Syslog**, sistem yöneticileri ve uygulama geliştiricileri tarafından kullanılan standart bir loglama mekanizmasıdır. Log mesajlarını kaydetmek, sınıflandırmak ve depolamak için kullanılır. Syslog mesajları genellikle aşağıdaki bileşenleri içerir:
- **Zaman Damgası**: Log mesajının oluşturulduğu tarih ve saat.
- **Önem Seviyesi (Severity)**: Log mesajının önem derecesi (0: Acil, 7: Debug gibi).
- **Mesaj İçeriği**: Log mesajının detayları.

Bu proje, syslog'un bu temel özelliklerini basit bir şekilde uygular.

---

## Özellikler

### 1. **Syslog Benzeri Log Ekleme**
- Log mesajları, syslog'ta olduğu gibi bir **zaman damgası**, **önem seviyesi** ve **mesaj içeriği** ile kaydedilir.
- Önem seviyeleri, syslog standartlarına uygun şekilde tanımlanmıştır:
  - `0`: Emergency (Acil)
  - `1`: Alert (Uyarı)
  - `2`: Critical (Kritik)
  - `3`: Error (Hata)
  - `4`: Warning (Uyarı)
  - `5`: Notice (Bildirim)
  - `6`: Informational (Bilgilendirme)
  - `7`: Debug (Hata Ayıklama)

### 2. **Log Görüntüleme**
- Kaydedilen tüm log mesajları, syslog formatına benzer şekilde görüntülenir.
- Her log mesajı, zaman damgası, önem seviyesi ve mesaj içeriği ile birlikte listelenir.

### 3. **Bellek Yönetimi**
- Log mesajları, **tek yönlü bağlı liste** yapısı kullanılarak dinamik olarak yönetilir.
- Program sonlandığında, bağlı liste yapısı temizlenir ve bellek sızıntısı önlenir.

---
## Kullanım

### 1. **Log Ekleme**
`add_log` fonksiyonu kullanılarak yeni log mesajları eklenebilir. Örnek kullanım:
```c
add_log(3, "Veritabanı bağlantı hatası.");
add_log(5, "Kullanıcı girişi başarılı.");
```

### 2. **Log Görüntüleme**
`display_logs` fonksiyonu kullanılarak kaydedilen tüm log mesajları görüntülenir. Örnek çıktı:
```
--- Tüm Loglar ---
[2023-10-05 14:30:45] Severity: 3, Mesaj: Veritabanı bağlantı hatası.
[2023-10-05 14:30:40] Severity: 5, Mesaj: Kullanıcı girişi başarılı.
------------------
```

### 3. **Bellek Temizleme**
Program sonlandığında, `free_logs` fonksiyonu kullanılarak bağlı liste yapısı temizlenir.

---

## Katkıda Bulunma

Bu proje açık kaynaklıdır ve katkılarınızı bekliyoruz. Katkıda bulunmak için lütfen bir "fork" oluşturun ve değişikliklerinizi bir "pull request" ile gönderin.

---

## Lisans

Bu proje MIT Lisansı altında lisanslanmıştır. Daha fazla bilgi için `LICENSE` dosyasına bakın.
