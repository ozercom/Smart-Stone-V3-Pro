# Smart Stone V3 Pro - Otomatik Taş Dizme Sistemi

Bu proje, 8 farklı taş haznesine sahip, CNC tabanlı ve vakum kontrollü bir otomatik taş dizme makinesidir. 10cm çapındaki hazneleri ile endüstriyel kapasitede üretim yapmak üzere tasarlanmıştır.

## 📂 Proje Yapısı
- **/MECHANICAL**: Üretim için STL ve DXF dosyaları.
- **/CODE**: Arduino kontrol yazılımı (V3 Pro).
- **/ELECTRONICS**: Bağlantı şemaları ve Satın Alma Listesi (BOM).
- **/DOCS**: Montaj ve kalibrasyon rehberleri.

## 🛠 Üretim ve Parça Listesi (Mechanical)

| Parça No | Dosya Adı | Yöntem | Adet | Malzeme / Not |
| :--- | :--- | :--- | :--- | :--- |
| 1 | `1_Hazne_Unitesi.stl` | 3D Baskı | 1 | PETG - %25 Doluluk |
| 2 | `2_Alt_Tabla.dxf` | CNC | 1 | 8mm Alüminyum (65x65cm) |
| 3 | `3_Z_Eksen_Blogu.stl` | 3D Baskı | 1 | PETG - %40 Doluluk |
| 4 | `4_Besleme_Kanali.stl` | 3D Baskı | 8 | PLA/PETG - Her hazne altına 1 adet |
| 5 | `5_Motor_Tutucu.stl` | 3D Baskı | 2 | PETG - %50 Doluluk |
| 6 | `6_Limit_Switch_Yuvasi.stl`| 3D Baskı | 2 | Herhangi bir filament |

## ⚙️ Teknik Parametreler
- **Hazne Çapı:** 100 mm (8 Adet)
- **Haraket Ekseni:** X (Revolver) ve Z (Vakum Kafası)
- **Kontrol Kartı:** Arduino Mega + RAMPS 1.4
- **Motorlar:** 2x Nema 17 Step Motor
- **Vakum:** 12V Diyafram Pompa + 0.5mm - 2mm Nozül seti

## 🔧 Kurulum Özet
1. `/MECHANICAL` içindeki dosyaları yukarıdaki adetlerde üretin.
2. `/ELECTRONICS/BOM.md` listesindeki standart parçaları temin edin.
3. `/CODE/SmartStone_V3.ino` dosyasını Arduino Mega'ya yükleyin.
4. `/DOCS/Montaj_Rehberi.md` adımlarını izleyerek mekanik kurulumu tamamlayın.