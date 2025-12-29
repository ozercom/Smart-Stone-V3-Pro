/*
 * SMART STONE V3 PRO - Master Control Software
 * Board: Arduino Mega + RAMPS 1.4
 * Motors: X (Revolver), Z (Vacuum Head)
 * Features: Homing, 8-Jar Selection, Vacuum Control
 */

#include <AccelStepper.h>

// --- PIN TANIMLAMALARI (RAMPS 1.4 Standart) ---
#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62

#define Z_MIN_PIN          18  // Z ekseni limit switch
#define VAKUM_POMPA_PIN    9   // RAMPS Fan çıkışı (Vakum için)

// --- AYARLAR ---
const int hazneSayisi = 8;
const int tamTurAdim = 200 * 16; // 1.8 derece motor + 16 mikrostep = 3200 adim
const int hazneArasiAdim = tamTurAdim / hazneSayisi; // Her hazne arasi 400 adim

// Motor Sürücü Tanımlama (1 = Sürücü ile kontrol)
AccelStepper revolver(1, X_STEP_PIN, X_DIR_PIN);
AccelStepper zEkseni(1, Z_STEP_PIN, Z_DIR_PIN);

void setup() {
  Serial.begin(115200);
  
  // Pin Modları
  pinMode(X_ENABLE_PIN, OUTPUT);
  pinMode(Z_ENABLE_PIN, OUTPUT);
  pinMode(VAKUM_POMPA_PIN, OUTPUT);
  pinMode(Z_MIN_PIN, INPUT_PULLUP);
  
  digitalWrite(X_ENABLE_PIN, LOW); // Motorlari aktif et
  digitalWrite(Z_ENABLE_PIN, LOW);

  // Hız ve İvme Ayarları
  revolver.setMaxSpeed(1000);
  revolver.setAcceleration(500);
  
  zEkseni.setMaxSpeed(2000);
  zEkseni.setAcceleration(1000);

  Serial.println("Sistem Baslatiliyor...");
  homingZ(); // Başlangıçta Z eksenini sıfırla
}

void loop() {
  // ÖRNEK SENARYO:
  // 1. Hazneyi seç -> Taşı al -> Bırak
  // selectJar(3); 
  // pickStone();
  // ... koordinatlara git ...
}

// --- FONKSİYONLAR ---

// Z Eksenini Sıfırlama (Homing)
void homingZ() {
  Serial.println("Z Ekseni Sifirlaniyor...");
  long initial_homing = 1;
  
  while (digitalRead(Z_MIN_PIN) != LOW) { 
    zEkseni.moveTo(initial_homing);
    initial_homing++;
    zEkseni.run();
  }
  zEkseni.setCurrentPosition(0);
  zEkseni.moveTo(-200); // Güvenli mesafeye çekil
  zEkseni.runToPosition();
  Serial.println("Z Tamam.");
}

// Hazne Seçimi (1'den 8'e kadar)
void selectJar(int jarID) {
  if(jarID < 1 || jarID > 8) return;
  
  Serial.print(jarID);
  Serial.println(". Hazneye gidiliyor...");
  
  long hedefAdim = (jarID - 1) * hazneArasiAdim;
  revolver.runToNewPosition(hedefAdim);
}

// Taşı Vakumla Alma İşlemi
void pickStone() {
  Serial.println("Tas aliniyor...");
  zEkseni.runToNewPosition(5000); // Tablaya in (Bu değer kalibre edilecek)
  
  digitalWrite(VAKUM_POMPA_PIN, HIGH); // Vakumu aç
  delay(500);
  
  zEkseni.runToNewPosition(0); // Yukarı kalk
}

// Taşı Bırakma İşlemi
void releaseStone() {
  Serial.println("Tas birakiliyor...");
  digitalWrite(VAKUM_POMPA_PIN, LOW); // Vakumu kapat
  delay(200);
}