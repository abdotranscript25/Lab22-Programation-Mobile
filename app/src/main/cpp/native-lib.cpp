#include <jni.h>
#include <string>
#include <algorithm>
#include <climits>
#include <android/log.h>

// El Hachimi Abdelhamid - Lab 22 JNI Demo

#define LOG_TAG "JNI_DEMO"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

// ============================================================
// 1) Hello World natif
// ============================================================
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_jnidemo_MainActivity_helloFromJNI(
        JNIEnv* env,
        jobject /* this */) {

    LOGI("Appel de helloFromJNI depuis le natif");
    return env->NewStringUTF(" Hello from C++ via JNI ! ");
}

// ============================================================
// 2) Factoriel avec gestion d'erreur
// ============================================================
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_jnidemo_MainActivity_factorial(
        JNIEnv* env,
        jobject /* this */,
        jint n) {

    // Vérification des nombres négatifs
    if (n < 0) {
        LOGE("Erreur : n negatif");
        return -1;
    }

    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
        // Vérification du dépassement (overflow)
        if (fact > INT_MAX) {
            LOGE("Overflow detecte pour n=%d", n);
            return -2;
        }
    }

    LOGI("Factoriel de %d calcule en natif = %lld", n, fact);
    return static_cast<jint>(fact);
}

// ============================================================
// 3) Inversion d'une chaine Java -> C++ -> Java
// ============================================================
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_jnidemo_MainActivity_reverseString(
        JNIEnv* env,
        jobject /* this */,
        jstring javaString) {

    // Vérification si la chaîne est nulle
    if (javaString == nullptr) {
        LOGE("Chaine nulle recue");
        return env->NewStringUTF("Erreur : chaine nulle");
    }

    // Conversion Java String → C++ string
    const char* chars = env->GetStringUTFChars(javaString, nullptr);
    if (chars == nullptr) {
        LOGE("Impossible de lire la chaine Java");
        return env->NewStringUTF("Erreur JNI");
    }

    std::string s(chars);
    env->ReleaseStringUTFChars(javaString, chars);

    // Inversion de la chaîne
    std::reverse(s.begin(), s.end());

    LOGI("String inversee = %s", s.c_str());
    // Conversion C++ string → Java String
    return env->NewStringUTF(s.c_str());
}

// ============================================================
// 4) Somme d'un tableau int[]
// ============================================================
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_jnidemo_MainActivity_sumArray(
        JNIEnv* env,
        jobject /* this */,
        jintArray array) {

    // Vérification si le tableau est nul
    if (array == nullptr) {
        LOGE("Tableau nul");
        return -1;
    }

    // Récupération de la taille du tableau
    jsize len = env->GetArrayLength(array);

    // Accès aux éléments du tableau
    jint* elements = env->GetIntArrayElements(array, nullptr);

    if (elements == nullptr) {
        LOGE("Impossible d'acceder aux elements du tableau");
        return -2;
    }

    // Calcul de la somme
    long long sum = 0;
    for (jsize i = 0; i < len; i++) {
        sum += elements[i];
    }

    // Libération des ressources
    env->ReleaseIntArrayElements(array, elements, 0);

    // Vérification du dépassement
    if (sum > INT_MAX) {
        LOGE("Overflow sur la somme");
        return -3;
    }

    LOGI("Somme du tableau = %lld", sum);
    return static_cast<jint>(sum);
}