
#include <assert.h>
#include <limits.h>
#include <stdio.h>

struct Image
{
  char** image;
  int height;
  int width;
};

void printImg(struct Image* img)
{
  for (int y = 0; y < img->height; ++y)
  {
    printf("%s\n", img->image[y]);
  }
  putc('\n', stdout);
}

int floodFillSize(struct Image* img, int x, int y, char roomChar, char newChar)
{
  if (x < 0 || x >= img->width || y < 0 || y >= img->height) return 0;
  if (img->image[y][x] != roomChar) return 0;

  img->image[y][x] = newChar;
  int size = 1;
  size += floodFillSize(img, x - 1, y, roomChar, newChar);
  size += floodFillSize(img, x + 1, y, roomChar, newChar);
  size += floodFillSize(img, x, y - 1, roomChar, newChar);
  size += floodFillSize(img, x, y + 1, roomChar, newChar);
  return size;
}

int main(void)
{
  char* lines[] = {
    (char[]){"..########################..........."},
    (char[]){"..#......................#...#####..."},
    (char[]){"..#..........########....#####...#..."},
    (char[]){"..#..........#......#............#..."},
    (char[]){"..#..........########.........####..."},
    (char[]){"..######......................#......"},
    (char[]){".......#..#####.....###########......"},
    (char[]){".......####...#######................"}
  };

  struct Image img = {
    .image = lines,
    .height = 8,
    .width = 37
  };

  char roomChar = '.';
  int largestSize = INT_MIN;

  for (int y = 0; y < img.height; ++y)
  {
    for (int x = 0; x < img.width; ++x)
    {
      if (img.image[y][x] == roomChar)
      {
        int size = floodFillSize(&img, x, y, roomChar, 'o');
        if (size > largestSize)
        {
          largestSize = size;
        }
        printImg(&img);
      }
    }
  }

  assert(largestSize == 109);

  return 0;
}