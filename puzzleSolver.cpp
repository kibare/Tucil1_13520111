/* 
RIZKY AKBAR ASMARAN
13520111
K03
TUGAS KECIL STRATEGI ALGORITMA IF2211
" WORD SEARCH PUZZLE "
*/

#include <iostream>
#include <fstream>
#include <ostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

unordered_set<string> listKata;
vector<vector<char>> puzzle;
set<string> kata2;

int N = 0;
int M = 0;
int perbandingan = 0;
int awal, akhir;
string file_puzzle,file_jawaban; 

void bacaListJawaban(string filename);
void bacaPuzzle(string filename);
void printPuzzle();
void printListJawaban();
void solver();

int main(){
    cout << "Masukkan File Puzzle: ";
    cin >> file_puzzle;
    cout << "Masukkan File Jawaban: ";
    cin >> file_jawaban;
    bacaListJawaban(file_jawaban);
    bacaPuzzle(file_puzzle);
    printPuzzle();
    uint64_t awal = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    solver();
    uint64_t akhir = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    cout << endl << "Proses selesai dalam waktu: "<< akhir-awal << " ms\n" << endl;
    cout << "Total Perbandingan Kata : " << perbandingan << endl;
    cout << "\n";
    printListJawaban();
    return 0;
}

bool tervalidasi(string str){
    int count = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] < 'A' || str[i] > 'Z'){
            return false;
        }else{
            count++;
        }
    }
    return count >= 0 && count <= 50;
}

void bacaPuzzle(string filename){
    ifstream puzzleReader(filename);
    string baris;
    if(puzzleReader.is_open()){
        while(getline(puzzleReader,baris)){
            if(N == 0){
                M = (baris.size()+1)/2;
            }
            N++;

            vector<char>row;
            for(int i = 0; i < baris.size(); i+=2){
                row.push_back(baris[i]);
            }
            puzzle.push_back(row);
        }
        puzzleReader.close();
    }
}

// check print puzzlenya udah bener atau belum
void printPuzzle(){
    cout << "Baris: " << N << "; Kolom: " << M <<endl;

    for (int i = 0; i < N; i++){
        vector<char> row = puzzle[i];
        for(int j = 0; j < M; j++){
            cout << row[j] << " ";
        }
        cout << endl;
    }
}

void bacaListJawaban(string filename){
    ifstream wordlistReader(filename);
    string kata;
    if(wordlistReader.is_open()){
        while(getline(wordlistReader, kata)){
            if(tervalidasi(kata)){
                listKata.insert(kata);
            }
        }
        wordlistReader.close();
    }
}

void printListJawaban(){
    cout << "List Jawaban: \n";
    for(auto const& i: listKata){
        cout << i << " \n";
    }
    cout << endl;
}

void checker_and_print(string x, int x_idx, int y_idx, int dir){
    char jawaban[N][M];
    int i, j, counter, x2, y2;
    perbandingan += 1;
    if(listKata.count(x)){ 
        for (i = 0; i < N; i++){
            for (j = 0; j < M; j++) {
                jawaban[i][j] = '-';
            }
        }
        if (dir == 0) {
            x2 = x_idx + x.length()-1;
            y2 = y_idx;
            counter = 0;
            while (counter < x.length()) {
                jawaban[x2][y2] = x[counter];
                counter += 1;
                x2 -= 1;
            }
        }
        else if (dir == 1) {
            x2 = x_idx + x.length()-1;
            y2 = y_idx - x.length()+1;
            counter = 0;
            while (counter < x.length()) {
                jawaban[x2][y2] = x[counter];
                counter += 1;
                x2 -= 1;
                y2 += 1;
            }
        }
        else if (dir == 2) {
            x2 = x_idx;
            y2 = y_idx;
            counter = 0;
            while (counter < x.length()) {
                jawaban[x2][y2] = x[counter];
                counter += 1;
                y2 += 1;
            }
        }
        else if (dir == 3) {
            x2 = x_idx ;
            y2 = y_idx ;
            counter = 0;
            while (counter < x.length()) {
                jawaban[x2][y2] = x[counter];
                counter += 1;
                y2 += 1;
                x2 += 1;
            }
        }
        else if (dir == 4) {
            x2 = x_idx;
            y2 = y_idx;
            counter = 0;
            while (counter < x.length()) {
                jawaban[x2][y2] = x[counter];
                counter += 1;
                x2 += 1;
            }
        }
        else if (dir == 5) {
            x2 = x_idx;
            y2 = y_idx;
            counter = 0;
            while (counter < x.length()) {
                jawaban[x2][y2] = x[counter];
                counter += 1;
                x2 += 1;
                y2 -= 1;
            }
        }
        else if (dir == 6) {
            x2 = x_idx;
            y2 = y_idx + x.length()-1;
            counter = 0;
            while (counter < x.length()) {
                jawaban[x2][y2] = x[counter];
                counter += 1;
                y2 -= 1;
            }
        }
        else if (dir == 7) {
            x2 = x_idx + x.length()-1;
            y2 = y_idx + x.length()-1;
            counter = 0;
            while (counter < x.length()) {
                jawaban[x2][y2] = x[counter];
                counter += 1;
                x2 -= 1;
                y2 -= 1;
            }
        }
        cout << "===========================================\n";
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) {
                cout <<jawaban[i][j] << " " ;
            }
            cout << endl;
        }
        kata2.insert(x);
    }
}

int minimum(int x, int y){
    if(x < y){
        return x;
    }
    return y;
}

// mencari melalui garis horizontal 2 arah sekaligus (kiri dan kanan)
void horizontal(int x, int y){
    string tester1 = "";
    string tester2 = "";
    for(int i = 0; i < minimum(M-y, 50); i++){
        tester1 = tester1 + puzzle[x][y+i];
        tester2 = puzzle[x][y+i] + tester2;
        if((i+1) >= 0){
            checker_and_print(tester1, x, y, 2);
            checker_and_print(tester2, x, y, 6);
        }
    }
}

// mencari melalui garis vertikal dengan 2 arah sekaligus (atas dan bawah)
void vertikal(int x, int y){
    string tester1 = "";
    string tester2 = "";
    for(int i = 0; i < minimum(N-x, 50); i++){
        tester1 = tester1 + puzzle[x+i][y];
        tester2 = puzzle[x+i][y] + tester2;
        if((i+1) >= 0){
            checker_and_print(tester1, x, y, 4);
            checker_and_print(tester2, x, y, 0);
        }
    }
}

// mencari melalui garis diagonal dengan 2 arah (kiri atas dan kanan bawah)
void diagonal1(int x, int y){
    string tester1 = "";
    string tester2 = "";
    for(int i = 0; i < minimum(50, minimum(N-x, M-y)); i++){
        tester1 = tester1 + puzzle[x+i][y+i];
        tester2 = puzzle[x+i][y+i] + tester2;
        if((i+1) >= 0){
            checker_and_print(tester1, x, y, 3);
            checker_and_print(tester2, x, y, 7);
        }
    }
}

// mencari melalui garis diagonal dengan 2 arah (kiri bawah dan kanan atas)
void diagonal2(int x, int y){
    string tester1 = "";
    string tester2 = "";
    for(int i = 0; i < minimum(50, minimum(N-x, y+1)); i++){
        tester1 = tester1 + puzzle[x+i][y-i];
        tester2 = puzzle[x+i][y-i] + tester2;
        if((i+1) >= 0){
            checker_and_print(tester1, x, y, 5);
            checker_and_print(tester2, x, y, 1);
        }
    }
}

void solver(){
    for (int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){
            horizontal(x,y);
            vertikal(x,y);
            diagonal1(x,y);
            diagonal2(x,y);
        }
    }
}