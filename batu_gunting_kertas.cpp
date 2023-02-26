// author : rkereh
// repository : github.com/kereh
// tested on : Linux 5.15.0-1029-gcp
// os : Ubuntu 20.04

#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <vector>

// class batu, gunting kertas
class BGK {
  // dengan akses public
public:
  // atribut
  bool loop = true;
  // vector/dynamic array yang menyimpan pilihan
  std::vector<std::string> pilihan = {"batu", "gunting", "kertas"};
};

// fungsi AI
int ai() {

  // membuat objek BGK dengan nama "ai_object"
  BGK ai_object;
  // mendefinisikan variabel min dan max dengan tipe data int
  int min = 0, max = 2;

  // fungsi untuk mengenerate nomor acak setiap waktu
  // jadi tiap kita menjalankan program, fungsi ini akan memberikan
  // nomor yang acak
  srand(time(nullptr));

  // variabel yang menyimpan nomor acak dari fungsi diatas
  // yang dimana batas acak untuk nilai minimum adalah 0
  // dan batas acak nilai maximum adalah 2
  int random = rand() % (max - min + 1) + min;

  // mengembalikan nilai random
  return random;
}

// fungsi score_sistem
// fungsi untuk mencari/memeriksa pemenang dan jawaban
// dengan 2 parameter
// parameter 1 : jwb_player = jawaban player dengan tipe data int
// parameter 2 : jwb_ai = jawaban ai dengan tipe data int
void score_sistem(int jwb_player, int jwb_ai) {
  // membuat object dari BGK class dengan nama score_obj
  BGK score_obj;
  // variabel yang menampung jawaban berdasarkan pilihan dari player dan ai
  std::string player = score_obj.pilihan[jwb_player];
  std::string ai = score_obj.pilihan[jwb_ai];

  // tampilkan player dengan jawaban, begitu juga dengan ai
  std::cout << "\n[+] player : " << player << std::endl;
  std::cout << "[+] ai : " << ai << std::endl;
  std::cout << "\n[!] memeriksa hasil..." << std::endl;

  // memberi jeda 1 detik sebelum lanjut
  sleep(1);

  // PERCABANGAN
  // menentukan siapa pemenang
  if (player == ai) { // jika pilihan player dan ai sama
    // maka
    std::cout << "[!] pilihan sama!" << std::endl;

  } else if ((jwb_player == 0 &&
              jwb_ai == 1) || // jika player = batu dan ai = gunting
             (jwb_player == 1 &&
              jwb_ai == 2) || // jika player = gunting dan ai = kertas
             (jwb_player == 2 &&
              jwb_ai == 0)) { // jika player = kertas dan ai = batu
    // maka, player menang
    std::cout << "[+] Player menang" << std::endl;
    // jeda 3 detik
    sleep(3);

  } else { // sebaliknya, jika kondisi diatas tidak terpenuhi
    // maka, ai yang menang
    std::cout << "[+] AI menang" << std::endl;
    // jeda 3 detik
    sleep(3);
  }
}

// fungsi menu
// menampilkan pilihan
void menu() {
  // buat object dari BGK dengan nama menu_obj
  BGK menu_obj;
  // tampilkan jdul program
  std::cout << "\n\n Batu Gunting Kertas \n\n\n";
  // looping sebanyak pilihan, untuk mendapatkan index dari masing" elemen
  // yang ada di atribut pilihan
  for (int i = 0; i < menu_obj.pilihan.size(); i += 1) {
    // tampilkan berdasarkan index
    std::cout << "[" << i + 1 << "] " << menu_obj.pilihan[i] << std::endl;
  }
  // tambahkan menu untuk keluar dari program
  std::cout << "[4] keluar" << std::endl;
}

// fungsi main, fungsi yang utama
int main() {
  // buat object dari BGK dengan nama main_obj
  BGK main_obj;
  // variabel status yang nantinya akan digunakan untuk menjalankan program
  // secara berulang 'loop'
  bool status = main_obj.loop; // true
  // looping selama variabel status bernilai = true
  while (status) {
    // deklarasi variabel
    int pilih;
    // panggil fungsi menu, untuk menampilkan menu
    menu();
    // tanya user, sekaligus menyimpan nilai input dari user
    std::cout << "\n[?] pilih : ";
    std::cin >> pilih;
    // jalankan fungsi ai, supaya ai dapat memilih : batu, gunting atau kertas
    // secara acak simpan pilihan ai kedalam variabel pilihan_ai
    int pilihan_ai = ai();
    // PERCABANGAN
    if (pilih == 4) { // jika player memilih menu no 4
      // maka ubah nilai status menjadi kebalikan nilai status sebelumnya
      // yang dimana status = true menjadi status = false
      // maka program akan berhenti
      status = !status; // status = negasi dari status

    } else if (pilih == 1) { // jika player pilih no 1
      // maka masukan pilihan dari player dan ai kedalam fungsi parameter
      // score_sistem
      score_sistem(pilih - 1, pilihan_ai);

    } else if (pilih == 2) {
      score_sistem(pilih - 1, pilihan_ai);

    } else if (pilih == 3) {
      score_sistem(pilih - 1, pilihan_ai);

    } else { // sebaliknya, jika user memasukan nomor atau pilihan yang tidak
             // ada dimenu
      // maka, beri tahu player bahwa pilihan tersebut tdk ad di menu
      // dan hentikan program
      std::cout << "\n[x] input invalid" << std::endl;
      status = !status;
    }
  }
  // kembalikan nilai ap saja yng bertipe data int
  // karena fungsi main mempunyai tipe data int
  return 0;
}
