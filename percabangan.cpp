// Author : kereh
// Repository : https://www.github.com/kereh
// Tested on : Archlinux 6.1.14-1-lts

#include <iostream>
#include <vector>
// fungsi binary search dengan 4 parameter
// parameter 1 = int x = data
// parameter 2 = int y = low
// parameter 3 = int z = high
// parameter 4 = int n = target
int binary_search(std::vector<int> x, int y, int z, int n) {
  // melakukan looping dengan "while (kondisi)"
  // lakukan looping selama y kurang dari z
  while (y < z) {
    // menentukan nilai mid
    // dengan menambahkan low(y) dan high(z) lalu dibagi dengan 2
    int mid = (y + z) / 2;
    // lakukan percabangan
    // jika elemen dengan index mid sama dengan target(n)
    if (x[mid] == n) {
      // maka tampilkan index dari elemen dalam array
      return mid;
      // dan jika elemen dengan index mid kurang dari target(n)
      // yang artinya jika target berada di sebelah kanan elemen
      // contoh :
      // [1,2,3,4,5,6]
      //			^		^
      // 			m		n
      // m = mid dan n = target
    } else if (x[mid] < n) {
      // maka, kita buat nilai low menjadi mid
      // dan tambahkan 1
      y = mid + 1;
      // sebaliknya, jika elemen dengan index mid lebih dari target(n)
      // yang artinya jika target berada di sebelah kiri elemen
      // contoh :
      // [1,2,3,4,5,6]
      //	^		^
      // 	n		m
      // m = mid dan n = target
    } else {
      // maka, kita buat nilai high menjadi mid
      // dan kurangi 1
      z = mid - 1;
    }
  }
  // jika target tidak ditemukan maka
  // kembalikan nilai negatif
  return -1;
}

// fungsi main atau fungsi utama
int main() {
  // variabel data
  std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // nilai low = 0
  int low = 0;
  // nilai high = banyaknya elemen dalam array
  int high = data.size();
  // elemen yang akan kita cari didalam array
  // contoh target
  int target = 1;
  // jalankan fungsi binary search
  // dengan parameter low, high, dan target
  // masukan fungsi kedalam variabel
  int result = binary_search(data, low, high, target);
  // jika variabel result memberikan nilai = -1
  (result == -1)
      // maka
      ? std::cout << target << " tidak ditemukan\n"
      // sebaliknya
      : std::cout << target << " ditemukan pada index " << result << std::endl;
  // return sebuah angka
  // karena fungsi main menggunakan tipe data int
  return 0;
}
