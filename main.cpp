
#include <iostream>
#include <math.h>

using namespace std;

char assignLetter(int num) {
    if (num == 7){
        return 'A';
      }
      else if (num == 8){
        return 'B';
      }
      else if (num == 9){
        return 'C';
      }
      else if (num == 10){
        return 'D';
      }
      else if (num == 11){
        return 'E';
      }
      else if (num == 12){
        return 'F';
      }
      else if (num == 13){
        return 'G';
      }
      else if (num == 14){
        return 'H';
      }
      else if (num == 15){
        return 'I';
      }
      else if (num == 16){
        return 'J';
      }
      else if (num == 17){
        return 'K';
      }
      else if (num == 18){
        return 'L';
      }
      else if (num == 19){
        return 'M';
      }
      else if (num == 20){
        return 'N';
      }
      else if (num == 21){
        return 'O';
      }
      else if (num == 22){
        return 'P';
      }
      else if (num == 23){
        return 'Q';
      }
      else if (num == 24){
        return 'R';
      }
      else if (num == 25){
        return 'S';
      }
      else if (num == 26){
        return 'T';
      }
      else if (num == 27){
        return 'U';
      }
      else if (num == 28){
        return 'V';
      }
      else if (num == 29){
        return 'W';
      }
      else if (num == 30){
        return 'X';
      }
      else if (num == 31){
        return 'Y';
      }
      else if (num == 32){
        return 'Z';
      }
      else if (num == 33){
        return ' ';
      }
      else if (num == 34){
        return '"';
      }
      else if (num == 35){
        return ',';
      }
      else if (num == 36){
        return '.';
      }
      else if (num == 37){
        return '\'';
      }
      return num;
    }

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int modularInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

void findPQ(int n) {
  int p=0;
  int q=0;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
        p = i;
        q = n / i;
        break;
    }
  }
  if (p == 0 || q == 0) {
    cout << "Error: Unable to find p and q for n = " << n << endl;
  } else {
    cout << "p = " << p << ", q = " << q << endl;
  }
}


int modularExponentiation(int base, int exponent, int modulus) {
    int result = 1;
    base = base % modulus;
    while (exponent > 0) {
        if (exponent & 1) {
            result = (result * base) % modulus;
        }
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

int decryption(int ciphertext, int d, int n) {
    //return modularExponentiation(ciphertext, d, n);
    int t = 1;
    for(int j = 0; j < d; j++) {
      int t = 1;
      t = (t * ciphertext) % n;
    }
  return t;
}

int main() {
    int e;
    int n;
    int p = 0;
    int q = 0;
    int m;
    //int i = 0;
  
    cout << "Enter e: ";
    cin >> e;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter m: ";
    cin >> m;
  
    findPQ(n);
  
    int phi = (p - 1) * (q - 1);
    int d = modularInverse(e, phi);
    
  
    int ciphertext[m];
    int plaintext[m];
  
    cout << "Enter ciphertext: ";
    for (int i = 0; i < m; ++i) {
      cin >> ciphertext[i];
      plaintext[i] = decryption(ciphertext[i], d, n);

    }
  
    if (gcd(e, phi) != 1) {
        cout << "Public key is not valid!" << endl;
        return 1;
    }
 
    for (int i = 0; i < m; ++i) {
          //plaintext[i] = decryption(ciphertext[i], d, n);
          cout << plaintext[i];
      }
      cout << endl;
  
    for (int i = 0; i < m; ++i) {
      //plaintext[i] = decryption(ciphertext[i], d, n);
      cout << assignLetter(plaintext[i]);
  }
      return 0;
  
}
