#ifndef RED-BLUE_H_INCLUDED
#define RED-BLUE_H_INCLUDED

typedef struct tagBITMAPFILEHEADER {
   WORD bfType;
   DWORD bfSize;
   WORD bfReserved1;
   WORD bfReserved2;
   DWORD bfOffBits;
 } BITMAPFILEHEADER;
 typedef struct tagBITMAPINFOHEADER {
   DWORD biSize;
   LONG biWidth;
   LONG biHeight;
   WORD biPlanes;
   WORD biBitCount;
   DWORD biCompression;
   DWORD biSizeImage;
   LONG biXPelsPerMeter;
   LONG biYPelsPerMeter;
   DWORD biClrUsed;
   DWORD biClrImportant;
 } BITMAPINFOHEADER;
 typedef struct tagRGBTRIPLE {
   BYTE rgbtBlue;
   BYTE rgbtGreen;
   BYTE rgbtRed;
 } RGBTRIPLE;

#endif // RED-BLUE_H_INCLUDED
