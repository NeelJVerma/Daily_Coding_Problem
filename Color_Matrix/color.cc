/*
Given a 2-D matrix representing an image, a location of a pixel in the screen and a color C, replace the color of the given pixel and all adjacent same colored pixels with C.

For example, given the following matrix, and location pixel of (2, 2), and 'G' for green:

B B W
W W W
W W W
B B B
Becomes

B B G
G G G
G G G
B B B
*/

#include <iostream>
#include <string>
using namespace std;

void FloodUtil(string* arr, int rows, int cols, int x, int y, char previous_color, char new_color) {
  if (x < 0 || x >= rows || y < 0 || y >= cols) {
    return;
  }

  if (arr[x][y] != previous_color) {
    return;
  }

  arr[x][y] = new_color;
  FloodUtil(arr, rows, cols, x + 1, y, previous_color, new_color);
  FloodUtil(arr, rows, cols, x - 1, y, previous_color, new_color);
  FloodUtil(arr, rows, cols, x, y + 1, previous_color, new_color);
  FloodUtil(arr, rows, cols, x, y - 1, previous_color, new_color);
}

void Flood(string* arr, int size, int x, int y, char new_color) {
  int previous_color = arr[x][y];
  FloodUtil(arr, size, arr[0].length(), x, y, previous_color, new_color);
}

int main() {
  string arr[] = {"BBW", "WWW", "WWW", "BBB"};
  Flood(arr, 4, 2, 2, 'G');

  for (int i = 0; i < 4; i++) {
    cout << arr[i] << endl;
  }

  return 0;
}