// Author : kereh
// Repository : https://www.github.com/kereh
// Tested on : Archlinux 6.1.14-1-lts

// note :
// feel free to learn from this simple code
// cheers, kereh.

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

class bgk_components {
  public:
    std::vector<std::string> bgk = {"batu", "gunting", "kertas"}; 
};

void first() {
  std::cout << "" << std::endl;
  std::cout << "Tugas 1 : Percabangan" << std::endl;
  std::cout << "" << std::endl;
  std::cout << "Nama : Dian R Kereh" << std::endl;
  std::cout << "Nim : 22011008" << std::endl;
  std::cout << "Repository : https://www.github.com/kereh" << std::endl;
  std::cout << "Project : Batu Gunting Kertas" << std::endl;
  std::cout << "" << std::endl;
}

void game_info(int a, int b) {
  std::cout << "[!] player score : " << a << std::endl;
  std::cout << "[!] ai score : " << b << std::endl;
}

void game_menu() {
  bgk_components menu;
  std::cout << "" << std::endl;
  for (int i = 0; i < menu.bgk.size(); i += 1) {
    std::cout << i+1 << " " << menu.bgk[i] << std::endl;
  }
}

std::string ai(std::vector<std::string> arr) {
  int low = 0;
  int high = arr.size() - 1;

  srand(time(nullptr));

  int random = rand() % (high - low + 1) + low;
  std::string result = arr[random];

  return result;
}

bool scoring_system(
  std::string a, 
  std::string b
) {

  if (a == "batu" && b == "gunting" || 
      a == "gunting" && b == "kertas" ||
      a == "kertas" && b == "batu"
  ) {
    return true;
  } else {
    return false;
  }
}

void game() {
  bgk_components bgk;

  std::string player_input;
  bool loop = true;

  while (loop) {

    static int player_score = 0;
    static int ai_score = 0;

    game_info(player_score, ai_score);
    game_menu();

    std::cout << "" << std::endl;
    std::cout << "[?] pilih (0 untuk keluar) : ";
    std::getline(std::cin, player_input);
    std::cout << "" << std::endl;

    int new_player_input = std::stoi(player_input);

    if (new_player_input == 0 || new_player_input < 1) {
      loop = !loop;
      std::cout << "[i] hasil akhir :" << std::endl;
      std::cout << "[o] player : " << player_score << std::endl;
      std::cout << "[o] ai : " << ai_score << std::endl;
    } else {
      if (new_player_input >= 4) {
        std::cout << "[!] masukan angka yang benar" << std::endl;
      } else { 
        std::string player_choose = bgk.bgk[new_player_input - 1];
        std::string ai_choose = ai(bgk.bgk);
        
        bool res = scoring_system(player_choose, ai_choose);

        if (res == 1) {
          std::cout << "[+] PLAYER MENANG\n" << std::endl; 
          player_score += 1;
        } else {
          std::cout << "[+] AI MENANG\n" << std::endl;
          ai_score += 1;
        }
      }
    }
  }
}

int main() {
  // tampilkan info pembuat
  first();
  // jalankan fungsi game
  game();
  // return int
  return 0;
}
