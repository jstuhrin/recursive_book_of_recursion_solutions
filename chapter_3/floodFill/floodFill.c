#include <stdio.h>

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
  printf("\n");
}

void floodFill(struct Image* img, int x, int y, char oldChar, char newChar)
{
    if (x < 0 || x >= img->width || y < 0 || y >= img->height) return;

    if (img->image[y][x] != oldChar) return;

    if (oldChar == newChar) return;

    img->image[y][x] = newChar;

    printImage(img);

    floodFill(img, x - 1, y, oldChar, newChar);
    floodFill(img, x + 1, y, oldChar, newChar);
    floodFill(img, x, y - 1, oldChar, newChar);
    floodFill(img, x, y + 1, oldChar, newChar);
}

int main(void)
{
    char* pixels[] = {
        (char[]){"..########################..........."},
        (char[]){"..#......................#...#####..."},
        (char[]){"..#..........########....#####...#..."},
        (char[]){"..#..........#......#............#..."},
        (char[]){"..#..........########.........####..."},
        (char[]){"..######......................#......"},
        (char[]){".......#..#####.....###########......"},
        (char[]){".......####...#######................"}
    };

    struct Image myImage = {
        .image  = pixels,
        .height = 8,
        .width  = 37
    };

    printImage(&myImage);
    floodFill(&myImage, 36, 0, '.', 'o');
    printImage(&myImage);

    return 0;
}