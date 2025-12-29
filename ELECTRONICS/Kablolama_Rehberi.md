# Smart Stone V3 Pro - Kablolama Rehberi

Tüm bağlantılar RAMPS 1.4 kartı üzerinden yapılacaktır.

### 1. Step Motor Bağlantıları
- **Revolver Motoru:** RAMPS üzerindeki **X-STEP** soketine takılmalıdır.
- **Z-Ekseni (Vakum) Motoru:** RAMPS üzerindeki **Z-STEP** soketine takılmalıdır.

### 2. Sensör ve Switch Bağlantıları
- **Z-Ekseni Limit Switch:** RAMPS üzerindeki **Z-MIN** pinlerine takılmalıdır. (S ve GND uçlarına).

### 3. Vakum Pompası Bağlantısı
- **Pompa Gücü:** RAMPS üzerindeki **D9 (Fan)** çıkışına bağlanmalıdır. 
- *Not:* Arduino kodunda `VAKUM_POMPA_PIN 9` olarak tanımlanmıştır.

### 4. Güç Girişi
- Güç kaynağından gelen 12V kabloları RAMPS üzerindeki ana terminale (+ / - kutuplarına dikkat ederek) vidalanmalıdır.