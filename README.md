# Lab22-Programation-Mobile - JNI (Java Native Interface)

## 📱 Description
Application Android réalisée dans le cadre du Lab 22 de développement mobile.  
Elle démontre la communication entre **Java** et **C++ natif** via **JNI (Java Native Interface)** pour effectuer des calculs intensifs et des manipulations de données côté natif.

## ✨ Fonctionnalités
- **Hello from JNI** : Appel simple retournant une chaîne depuis le C++
- **Factoriel natif** : Calcul avec gestion d'erreur (négatif, overflow)
- **Inversion de chaîne** : Manipulation de `String` Java en C++
- **Somme de tableau** : Traitement d'un `int[]` Java en C++
- **Logs natifs** : Affichage dans Logcat avec tag `JNI_DEMO`

## 🛠️ Technologies utilisées
- **Langages** : Java, C++
- **JNI** : Java Native Interface (pont Java ↔ C++)
- **NDK** : Native Development Kit
- **CMake** : Build system pour le code natif
- **Bibliothèques** : `log` (logs natifs), `jni.h`

## 📸 Captures d'écran

### Structure des packages
<img width="512" height="768" alt="package" src="https://github.com/user-attachments/assets/cfe3a204-7b53-4ff4-8924-5abb74e10e92" />

### CMakeLists.txt
<img width="805" height="506" alt="1" src="https://github.com/user-attachments/assets/5c39e514-fd8b-4f67-bfca-fd1436185481" />


### build.gradle (configuration CMake)
<img width="874" height="828" alt="2" src="https://github.com/user-attachments/assets/06323f0b-782f-4192-ba16-3eb6616262f2" />


### native-lib.cpp (code natif complet)
<img width="886" height="816" alt="nativ1" src="https://github.com/user-attachments/assets/7760d038-74bb-47fb-9102-e0b12478dfee" />
<img width="886" height="822" alt="nativ2" src="https://github.com/user-attachments/assets/20d1f431-62c2-4a74-a512-673b90df36d3" />
<img width="878" height="813" alt="nativ3" src="https://github.com/user-attachments/assets/a6c80504-96cf-4289-a504-ee571eaffe92" />
<img width="858" height="801" alt="nativ4" src="https://github.com/user-attachments/assets/95aae5d4-485c-4850-b3fc-f8f2042df78c" />


### MainActivity.java (déclaration des méthodes natives)
<img width="896" height="845" alt="main1" src="https://github.com/user-attachments/assets/eeb34aa1-9a23-46db-b845-af7a9ac57e14" />
<img width="899" height="845" alt="main2" src="https://github.com/user-attachments/assets/42106b8a-1262-417d-a2d6-221ee8e2f0e2" />
<img width="905" height="738" alt="main3" src="https://github.com/user-attachments/assets/64aa1cf2-cc5d-42a5-adc7-57552ebeb89c" />


### activity_main.xml (layout)
<img width="1335" height="835" alt="lay1" src="https://github.com/user-attachments/assets/196dadbf-c4df-4a0e-9dbc-02aa0c1445d9" />



### Test 1 : valeur normale
<img width="344" height="614" alt="test1" src="https://github.com/user-attachments/assets/32ff809e-4266-49a0-a402-26750297f09f" />


### Test 2 : valeur négative
<img width="380" height="721" alt="test2" src="https://github.com/user-attachments/assets/c483793a-0f65-4075-b88f-4f741d7b9578" />


### Test 3 : dépassement, chaîne vide et tableau vide
<img width="357" height="661" alt="test3" src="https://github.com/user-attachments/assets/4d59ace2-5cd4-4f3a-8c80-54229401f33a" />


## 🎥 Démonstration vidéo


https://github.com/user-attachments/assets/0a94eef4-3617-4a6c-a193-145a4c3e7653


### Test MobSF
<img width="1600" height="822" alt="Mobsf" src="https://github.com/user-attachments/assets/d19319a4-d2a5-4cb7-874a-8c11f4e34ff8" />
<img width="1066" height="763" alt="Mobsf2" src="https://github.com/user-attachments/assets/3c4daf76-1617-432a-8153-63bd4ab14cea" />


## 🧠 Concepts clés abordés

| Concept | Rôle |
|---------|------|
| **JNI** | Interface entre Java et le code natif C/C++ |
| **NDK** | Ensemble d'outils pour compiler C++ sur Android |
| **CMake** | Configuration de la compilation native |
| **`native` keyword** | Déclare une méthode implémentée en C++ |
| **`System.loadLibrary()`** | Charge la bibliothèque partagée `.so` |
| **`extern "C"`** | Empêche le name mangling du C++ |
| **`JNIEXPORT` / `JNICALL`** | Exportation et convention d'appel JNI |
| **`JNIEnv*`** | Accès aux fonctions JNI (conversion, tableaux, etc.) |

## 🔧 Méthodes importantes

### Côté Java
| Méthode | Rôle |
|---------|------|
| `public native String helloFromJNI()` | Appelle le C++ pour obtenir un message |
| `public native int factorial(int n)` | Calcul du factoriel en natif |
| `public native String reverseString(String s)` | Inverse une chaîne en C++ |
| `public native int sumArray(int[] values)` | Somme d'un tableau en natif |
| `System.loadLibrary("native-lib")` | Charge `libnative-lib.so` |

### Côté C++ (JNI)
| Fonction | Rôle |
|----------|------|
| `env->NewStringUTF()` | Crée un String Java depuis C++ |
| `env->GetStringUTFChars()` | Convertit `jstring` → `const char*` |
| `env->ReleaseStringUTFChars()` | Libère la mémoire du string converti |
| `env->GetArrayLength()` | Récupère la taille d'un tableau |
| `env->GetIntArrayElements()` | Accède aux éléments d'un `int[]` |
| `env->ReleaseIntArrayElements()` | Libère le tableau |
| `__android_log_print()` | Écrit dans Logcat depuis le natif |


## 👤 Auteur
**abdotranscript25** El Hachimi Abdelhamid - Lab22 Programation Mobile

## 📅 Date de réalisation
Avril 2026

