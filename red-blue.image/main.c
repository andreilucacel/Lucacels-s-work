 #include <stdlib.h>
 #include <stdio.h>
 #include <windows.h>

 int main(){
   FILE* fp = fopen("img.bmp", "rb+");
   BITMAPFILEHEADER head;
   fread(&head, sizeof(head), 1, fp);
   BITMAPINFOHEADER info;
   fread(&info, sizeof(info), 1, fp);
   int h = info.biHeight;
   int w = info.biWidth;
   RGBTRIPLE* pixels = calloc(sizeof(RGBTRIPLE), h*w);
   fread(pixels, sizeof(RGBTRIPLE), h*w, fp);
   for(int i = 0; i<h*w; i++) {
       pixels[i].rgbtBlue = 255;
       pixels[i].rgbtGreen = 0;
       pixels[i].rgbtRed = 0;
   }
   int h2 = h/2, h4 = h/4, w2 = w/2;
   for(int i = h2 - h4; i < h2 + h4; i++){
       for(int j = w2 - h4; j < w2 + h4; j++){
           pixels[i * w + j].rgbtBlue = 0;
           pixels[i * w + j].rgbtRed = 255;
       }
   }
   fseek(fp, sizeof(head) + sizeof(info), SEEK_SET);
   fwrite(pixels, sizeof(RGBTRIPLE), h*w, fp);
   fclose(fp);
   return 0;
 }
