
#include <stdio.h>
#include <assert.h>

struct Image
{
  char** image;
  int height;
  int width;
};

void printImage(struct Image* img)
{
  for (int y = 0; y < img->height; ++y)
  {
    printf("%s\n", img->image[y]);
  }
  putc('\n', stdout);
}

void floodFill(struct Image* img, int y, int x, char roomChar, char newChar)
{
  if (y < 0 || y >= img->height || x < 0 || x >= img->width) return;
  if (img->image[y][x] != roomChar) return;

  img->image[y][x] = newChar;
  printImage(img);
  floodFill(img, y - 1, x, roomChar, newChar);
  floodFill(img, y + 1, x, roomChar, newChar);
  floodFill(img, y, x - 1, roomChar, newChar);
  floodFill(img, y, x + 1, roomChar, newChar);
}

int main(void)
{
  char* lines[] = {
        (char[]){"..########################..........."},
        (char[]){"..#..........#......#....#...#####..."},
        (char[]){"..#..........########....#####...####"},
        (char[]){"..#..........#.#....#............#.#."},
        (char[]){"..#..........########.........#######"},
        (char[]){"..######............#.........#......"},
        (char[]){".......#..#####.....###########......"},
        (char[]){".......####...#######................"}
  };

  struct Image img = {
    .image = lines,
    .height = 8,
    .width = 37
  };

  char roomChar = '.';

  int count = 0;

  for (int y = 0; y < img.height; ++y)
  {
    for (int x = 0; x < img.width; ++x)
    {
      if (img.image[y][x] == roomChar) ++count;
      floodFill(&img, y, x, roomChar, count % 10 + '0');
    }
  }

  assert(count == 11);

  return 0;
}