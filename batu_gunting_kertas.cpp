// author : rkereh
// repository : github.com/kereh
// tested on : Linux 5.15.0-1029-gcp
// os : Ubuntu 20.04

#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <vector>

class BGK {
public:
  bool loop = true;
  std::vector<std::string> pilihan = {"batu", "gunting", "kertas"};
};

int ai() {
  BGK ai_object;
  int min = 0, max = 2;

  srand(time(nullptr));

  int random = rand() % (max - min + 1) + min;

  return random;
}

void score_sistem(int jwb_player, int jwb_ai) {
  BGK score_obj;

  std::string player = score_obj.pilihan[jwb_player];
  std::string ai = score_obj.pilihan[jwb_ai];

  std::cout << "\n[+] player : " << player << std::endl;
  std::cout << "[+] ai : " << ai << std::endl;
  std::cout << "\n[!] memeriksa hasil..." << std::endl;

  sleep(1);

  if (player == ai) {

    std::cout << "[!] pilihan sama!" << std::endl;

  } else if ((jwb_player == 0 && jwb_ai == 1) ||
             (jwb_player == 1 && jwb_ai == 2) ||
             (jwb_player == 2 && jwb_ai == 0)) {

    std::cout << "[+] Player menang" << std::endl;
    sleep(3);

  } else {

    std::cout << "[+] AI menang" << std::endl;
    sleep(3);
  }
}

void menu() {

  BGK menu_obj;

  std::cout << "\n\n Batu Gunting Kertas \n\n\n";

  for (int i = 0; i < menu_obj.pilihan.size(); i += 1) {

    std::cout << "[" << i + 1 << "] " << menu_obj.pilihan[i] << std::endl;
  }

  std::cout << "[4] keluar" << std::endl;
}

int main() {
  BGK main_obj;

  bool status = main_obj.loop; // true

  while (status) {

    int pilih;

    menu();

    std::cout << "\n[?] pilih : ";
    std::cin >> pilih;

    int pilihan_ai = ai();

    if (pilih == 4) {
      status = !status;

    } else if (pilih == 1) {
      score_sistem(pilih - 1, pilihan_ai);

    } else if (pilih == 2) {
      score_sistem(pilih - 1, pilihan_ai);

    } else if (pilih == 3) {
      score_sistem(pilih - 1, pilihan_ai);

    } else {
      std::cout << "\n[x] input invalid" << std::endl;
      status = !status;
    }
  }

  return 0;
}
