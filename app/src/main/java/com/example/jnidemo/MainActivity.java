package com.example.jnidemo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

// El Hachimi Abdelhamid - Lab 22 JNI Demo

public class MainActivity extends AppCompatActivity {

    // ============================================================
    // DÉCLARATION DES MÉTHODES NATIVES (implémentées en C++)
    // ============================================================

    // 1) Retourne un message simple
    public native String helloFromJNI();

    // 2) Calcule la factorielle d'un nombre
    public native int factorial(int n);

    // 3) Inverse une chaîne de caractères
    public native String reverseString(String s);

    // 4) Calcule la somme d'un tableau d'entiers
    public native int sumArray(int[] values);

    // ============================================================
    // CHARGEMENT DE LA BIBLIOTHÈQUE NATIVE
    // ============================================================
    static {
        // Charge libnative-lib.so (ne pas mettre le préfixe "lib" ni ".so")
        System.loadLibrary("native-lib");
    }

    // ============================================================
    // ACTIVITÉ PRINCIPALE
    // ============================================================
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Récupération des vues
        TextView tvHello = findViewById(R.id.tvHello);
        TextView tvFact = findViewById(R.id.tvFact);
        TextView tvReverse = findViewById(R.id.tvReverse);
        TextView tvArray = findViewById(R.id.tvArray);

        // 🔍 LOGS DE DÉBOGAGE
        android.util.Log.d("JNI_UI", "tvHello trouvé ? " + (tvHello != null));
        android.util.Log.d("JNI_UI", "tvFact trouvé ? " + (tvFact != null));
        android.util.Log.d("JNI_UI", "tvReverse trouvé ? " + (tvReverse != null));
        android.util.Log.d("JNI_UI", "tvArray trouvé ? " + (tvArray != null));

        // ===== TEST 1 : Hello World =====
        String helloMessage = helloFromJNI();
        android.util.Log.d("JNI_UI", "helloMessage = " + helloMessage);
        if (tvHello != null) {
            tvHello.setText(helloMessage);
        } else {
            android.util.Log.e("JNI_UI", "tvHello est NULL !");
        }

        // ===== TEST 2 : Factoriel =====
        int fact13 = factorial(13);
        android.util.Log.d("JNI_UI", "fact = " + fact13);
        if (tvFact != null) {
            tvFact.setText(" Factoriel de 13  = " + fact13);
        } else {
            android.util.Log.e("JNI_UI", "tvFact est NULL !");
        }

        // ===== TEST 3 : Inversion de chaîne =====
        String original = "JNI is powerful!";
        String reversed = reverseString(original);
        android.util.Log.d("JNI_UI", "reversed = " + reversed);
        if (tvReverse != null) {
            tvReverse.setText(" Texte original : " + original + "\n🔄 Texte inversé : " + reversed);
        } else {
            android.util.Log.e("JNI_UI", "tvReverse est NULL !");
        }

        // ===== TEST 4 : Somme d'un tableau =====
        int[] numbers = {10, 40, 60, 80, 50};
        int sum = sumArray(numbers);
        android.util.Log.d("JNI_UI", "sum = " + sum);
        if (tvArray != null) {
            tvArray.setText(" Tableau : [10, 40, 60, 90, 50]\n Somme = " + sum);
        } else {
            android.util.Log.e("JNI_UI", "tvArray est NULL !");
        }
    }
}