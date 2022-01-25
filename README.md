# Word Search Puzzle dengan Algoritma Brute Force
*by: Rizky Akbar Asmaran - 13520111

## Word Search Puzzle 
Word search puzzle adalah permainan kata dimana pemain harus menemukan beberapa kata 
tersembunyi dalam kumpulan huruf acak. Kumpulan huruf tersebut biasa diletakkan pada “papan” 
berbentuk segi empat atau dapat disebut juga matriks huruf. Kata-kata pada matriks huruf ini dapat 
ditemukan dalam delapan arah yang mungkin, yaitu, vertikal ke atas, vertikal ke bawah, horizontal 
ke kanan, horizontal ke kiri, diagonal ke kanan atas, diagonal ke kanan bawah, diagonal ke kiri 
atas, dan diagonal ke kiri bawah. Word search puzzle pertama kali dibuat oleh Noeman E. Gibat. 
Puzzle ini dipublikasikan dalam the Selenby Digest pada 1 Maret 1968 di Norman, Oklahoma. 
Setelah itu word search puzzle mulai terkenal di daerahnya. Kemudian beberapa guru meminta 
salinannya untuk digunakan sebagai alat mengajar. Akhirnya permainan itu tersebar setelah 
seorang guru mengirimkan salinannya kepada teman-teman di kota lain. Sekarang word search 
puzzle bisa ditemukan dengan mudah di koran, majalah, bahkan internet (Paragraf di atas dikutip 
dari sini: https://informatika.stei.itb.ac.id/~rinaldi.munir/Stmik/2016-
2017/Makalah2017/Makalah-IF2211-2017-077.pdf )
 
 ## Instalasi
 clone repositori ini dengan command ini pada terminal: 
 ```
git clone https://github.com/kibare/Tucil-Stima-1.git
 ```
 
 ## Menjalankan Program
 - Masuk ke dalam folder hasil clone
 - Compile terlebih dahulu program menggunakan g++, kemudian jalankan program dengan nama file txt yang berisi puzzle sebagai argumen. gunakan command:
 ```
 g++ main.cpp && ./a.out ../test/[NAMA_FILE.txt]
 ```
 atau pada visual studio code:
  ```
 cd "c:\Users\sasga\Documents\GitHub\Tucil-Stima-1\src\" ; if ($?) { g++ puzzleSolver.cpp -o puzzleSolver } ; if ($?) { .\puzzleSolver }
 ```
 lalu nanti terdapat input berupa file txt dengan format ../test/[nama file.txt]
