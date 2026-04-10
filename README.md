# Algorithm Playground

Repository ini berisi kumpulan tugas dan eksperimen algoritma dasar menggunakan bahasa C.
Fokus utama adalah mempelajari dan mengimplementasikan algoritma sorting seperti Bubble Sort dan Quick Sort.

## 📘 Tujuan

- Belajar dasar algoritma sorting di C.
- Memahami logika Bubble Sort dan Quick Sort secara lengkap.
- Melihat contoh implementasi C yang mudah diikuti.
- Mengetahui perbedaan performa dan penggunaan kedua algoritma.

## 🧩 Struktur File

- `program1.c` - implementasi Bubble Sort sederhana untuk angka.
- `program2.c` - Bubble Sort untuk mengurutkan nama mahasiswa secara descending berdasarkan string.
- `program3.c` - contoh Bubble Sort lainnya dengan input angka.
- `sorting.c` - fungsi `bubble_sort()` sebagai contoh pemisahan logika ke fungsi terpisah.
- `quick-sort.c` - percobaan Quick Sort (kode ini masih eksperimen dan mungkin perlu perbaikan logika).
- `tugas-quick-bubble-hantu.c` - tugas khusus Bubble Sort dengan konsep elemen "hantu".

## 📖 Teori Lengkap Sorting

### Apa itu Sorting?
Sorting adalah proses mengurutkan data menurut aturan tertentu, misalnya dari kecil ke besar (ascending) atau dari besar ke kecil (descending).
Sorting penting untuk:
- Memudahkan pencarian.
- Menyusun data agar tampilannya rapi.
- Meningkatkan efisiensi algoritma lain (misalnya pencarian biner).

### Bubble Sort: Teori Lengkap
Bubble Sort adalah algoritma pengurutan sederhana yang bekerja dengan membandingkan sepasang elemen bersebelahan dan menukarnya bila tidak sesuai urutan.

Langkah utama Bubble Sort:
1. Mulai dari elemen pertama.
2. Bandingkan elemen saat ini dengan elemen di sebelah kanannya.
3. Jika urutannya salah, tukar kedua elemen.
4. Lanjutkan sampai akhir array.
5. Ulangi proses sebanyak n-1 kali atau sampai tidak ada pertukaran.

Karakteristik Bubble Sort:
- Kompleksitas waktu: O(n²) pada kasus rata-rata dan terburuk.
- Kompleksitas ruang: O(1) (in-place).
- Stabil: elemen dengan nilai sama tetap mempertahankan urutan relatif.
- Cocok untuk dataset kecil dan untuk belajar konsep dasar sorting.

### Contoh Bubble Sort dalam C

```c
#include <stdio.h>

void bubble_sort(int array[], int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {
    int data[] = {5, 2, 9, 1, 7};
    int size = sizeof(data) / sizeof(data[0]);

    bubble_sort(data, size);

    printf("Hasil bubble sort:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}
```

### Quick Sort: Teori Lengkap
Quick Sort adalah algoritma sorting yang lebih cepat untuk banyak data. Ia menggunakan konsep "divide and conquer".

Langkah utama Quick Sort:
1. Pilih satu elemen sebagai pivot.
2. Partisi array sehingga semua elemen lebih kecil dari pivot berada di kiri, dan yang lebih besar berada di kanan.
3. Rekursif urutkan bagian kiri dan kanan.

Karakteristik Quick Sort:
- Kompleksitas rata-rata: O(n log n).
- Kompleksitas terburuk: O(n²) jika pivot buruk.
- Kompleksitas ruang: O(log n) untuk stack rekursi.
- Tidak stabil pada implementasi umum.
- Sangat efisien untuk dataset sedang sampai besar.

### Contoh Quick Sort dalam C

```c
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int low, int high) {
    int pivot = array[(low + high) / 2];
    int i = low;
    int j = high;

    while (i <= j) {
        while (array[i] < pivot) {
            i++;
        }
        while (array[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(&array[i], &array[j]);
            i++;
            j--;
        }
    }
    return i;
}

void quick_sort(int array[], int low, int high) {
    if (low < high) {
        int index = partition(array, low, high);
        if (low < index - 1) {
            quick_sort(array, low, index - 1);
        }
        if (index < high) {
            quick_sort(array, index, high);
        }
    }
}

int main() {
    int data[] = {34, 67, 23, 28, 98, 15, 84, 67, 28, 18};
    int size = sizeof(data) / sizeof(data[0]);

    quick_sort(data, 0, size - 1);

    printf("Hasil quick sort:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}
```

## 🔧 Penjelasan Implementasi C di Repo

- `program1.c` dan `program3.c` menampilkan Bubble Sort langsung di `main()`.
- `sorting.c` memisahkan logika Bubble Sort ke fungsi `bubble_sort()`.
- `program2.c` menunjukkan penggunaan Bubble Sort pada data string menggunakan `strcmp()`.
- `quick-sort.c` adalah percobaan Quick Sort; perhatikan bahwa pemilihan pivot dan partisi perlu diperbaiki sebelum digunakan secara produksi.
- `tugas-quick-bubble-hantu.c` menggabungkan konsep Bubble Sort dan validasi input khusus "hantu".

## 🚀 Cara Compile dan Jalankan

Gunakan GCC / MinGW di Windows. Contoh perintah:

```bash
gcc program1.c -o program1.exe
.\program1.exe
```

Untuk file lainnya:

```bash
gcc program2.c -o program2.exe
.\program2.exe

gcc program3.c -o program3.exe
.\program3.exe

gcc sorting.c -o sorting.exe
.\sorting.exe

gcc quick-sort.c -o quick-sort.exe
.\quick-sort.exe

gcc tugas-quick-bubble-hantu.c -o tugas-quick-bubble-hantu.exe
.\tugas-quick-bubble-hantu.exe
```

## ✅ Tips Belajar

1. Jalankan satu file C terlebih dahulu untuk memahami input dan output.
2. Tambahkan `printf()` sebelum dan sesudah sorting agar perubahan terlihat jelas.
3. Coba ubah urutan data input untuk melihat perbedaan waktu eksekusi.
4. Bandingkan logika Bubble Sort dan Quick Sort untuk memahami kapan setiap algoritma lebih cocok.
5. Jika ingin ulang, modifikasi Quick Sort dengan memilih pivot `array[(low + high) / 2]` atau `array[high]`.

## 🎯 Rekomendasi Latihan

- Tambahkan input pengguna di contoh Quick Sort.
- Ubah `tugas-quick-bubble-hantu.c` agar dapat memilih ascending atau descending.
- Buat fungsi `print_array()` untuk mencetak array agar kode lebih rapi.
- Implementasikan versi Bubble Sort yang berhenti lebih awal saat sudah terurut.

## 📌 Kesimpulan

README ini membantu kamu mempelajari teori sorting dan melihat implementasi C langsung.
Kamu bisa menggunakan contoh Bubble Sort dan Quick Sort sebagai dasar untuk eksperimen lebih lanjut.

