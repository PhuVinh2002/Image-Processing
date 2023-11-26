#include <stdio.h>
#include <stdlib.h>

#define Width 256
#define Height 256
#define Parts 64

void chiaMaTran(unsigned char image[Width][Height], unsigned char result[]){
        int partRows = Width / Parts;
        int partCols = Height / Parts;
    for (int i = 0; i < Parts; ++i) {
        for (int j = 0; j < Parts; ++j) {
            int sum = 0;
            for (int row = i * partRows; row < (i + 1) * partRows; ++row) {
                for (int col = j * partCols; col < (j + 1) * partCols; ++col) {
                    sum += image[row][col];
                }
            }
            result[i * Parts + j] = sum;
        }
    }
}

int Max(int a, int b, int c, int d){
        int max = a;

        if (b > max) {
            max = b;
        }
        if (c > max) {
            max = c;
        }
        if (d > max) {
            max = d;
        }
        return max;
}
int main(){
    FILE *inputFileDiagonalDown = fopen("C:\\Users\\Admin\\Desktop\\raw_DiagonalDown.dat", "rb");
    FILE *inputFileDiagonalUp = fopen("C:\\Users\\Admin\\Desktop\\raw_DiagonalUp.dat", "rb");
    FILE *inputFileHorizontal = fopen("C:\\Users\\Admin\\Desktop\\raw_Horizotal.dat", "rb");
    FILE *inputFileVertical = fopen("C:\\Users\\Admin\\Desktop\\raw_Vertical.dat", "rb");

    FILE *outputFileDiagonalDown = fopen("C:\\Users\\Admin\\Desktop\\raw_edgeDiagonalDown.dat", "wb");
    FILE *outputFileDiagonalUp = fopen("C:\\Users\\Admin\\Desktop\\raw_edgeDiagonalUp.dat", "wb");
    FILE *outputFileHorizontal = fopen("C:\\Users\\Admin\\Desktop\\raw_edgeHorizontal.dat", "wb");
    FILE *outputFileVertical = fopen("C:\\Users\\Admin\\Desktop\\raw_edgeVertical.dat", "wb");



    unsigned char imageDiagonalDown[Width][Height];
    unsigned char imageDiagonalUp[Width][Height];
    unsigned char imageHorizontal[Width][Height];
    unsigned char imageVertical[Width][Height];
    
    fread(imageDiagonalDown, 1, Width * Height, inputFileDiagonalDown);
    fread(imageDiagonalUp, 1, Width * Height, inputFileDiagonalUp);
    fread(imageHorizontal, 1, Width * Height, inputFileHorizontal);
    fread(imageVertical, 1, Width * Height, inputFileVertical);
    unsigned char winnerTakeAll;
    unsigned char zero = 0;
    unsigned char one = 1;
        for (int i = 0; i < Width; ++i) {
            for (int j = 0; j < Height; ++j) {
                winnerTakeAll = Max(imageDiagonalDown[i][j],imageDiagonalUp[i][j],imageHorizontal[i][j],imageVertical[i][j]);
                if(winnerTakeAll == imageDiagonalDown[i][j]){
                    if(winnerTakeAll > 127){
                        fwrite(&one, 1, 1, outputFileDiagonalDown);
                        fwrite(&zero, 1, 1, outputFileDiagonalUp);
                        fwrite(&zero, 1, 1, outputFileHorizontal);
                        fwrite(&zero, 1, 1, outputFileVertical);
                    }
                    else{
                        fwrite(&zero, 1, 1, outputFileDiagonalDown);
                        fwrite(&zero, 1, 1, outputFileDiagonalUp);
                        fwrite(&zero, 1, 1, outputFileHorizontal);
                        fwrite(&zero, 1, 1, outputFileVertical);
                    }
                }
                else if(winnerTakeAll == imageDiagonalUp[i][j]){
                    if(winnerTakeAll > 127){
                        fwrite(&one, 1, 1, outputFileDiagonalUp);
                        fwrite(&zero, 1, 1, outputFileDiagonalDown);
                        fwrite(&zero, 1, 1, outputFileHorizontal);
                        fwrite(&zero, 1, 1, outputFileVertical);
                    }
                    else{
                        fwrite(&zero, 1, 1, outputFileDiagonalUp);
                        fwrite(&zero, 1, 1, outputFileDiagonalDown);
                        fwrite(&zero, 1, 1, outputFileHorizontal);
                        fwrite(&zero, 1, 1, outputFileVertical);
                    }
                }
                else if(winnerTakeAll == imageHorizontal[i][j]){
                    if(winnerTakeAll > 127){
                        fwrite(&one, 1, 1, outputFileHorizontal);
                        fwrite(&zero, 1, 1, outputFileDiagonalUp);
                        fwrite(&zero, 1, 1, outputFileDiagonalDown);
                        fwrite(&zero, 1, 1, outputFileVertical);
                    }
                    else{
                        fwrite(&zero, 1, 1, outputFileDiagonalDown);
                        fwrite(&zero, 1, 1, outputFileDiagonalUp);
                        fwrite(&zero, 1, 1, outputFileHorizontal);
                        fwrite(&zero, 1, 1, outputFileVertical);
                    }
                }
                else if(winnerTakeAll == imageVertical[i][j]){
                    if(winnerTakeAll > 127){
                        fwrite(&one, 1, 1, outputFileVertical);
                        fwrite(&zero, 1, 1, outputFileDiagonalUp);
                        fwrite(&zero, 1, 1, outputFileHorizontal);
                        fwrite(&zero, 1, 1, outputFileDiagonalDown);
                    }
                    else{
                        fwrite(&zero, 1, 1, outputFileDiagonalDown);
                        fwrite(&zero, 1, 1, outputFileDiagonalUp);
                        fwrite(&zero, 1, 1, outputFileHorizontal);
                        fwrite(&zero, 1, 1, outputFileVertical);
                    }
                }
            }
        }
        fclose(inputFileDiagonalDown);
        fclose(inputFileDiagonalUp);
        fclose(inputFileHorizontal);
        fclose(inputFileVertical);

        fclose(outputFileDiagonalDown);
        fclose(outputFileDiagonalUp);
        fclose(outputFileHorizontal);
        fclose(outputFileVertical);

    FILE *FileDiagonalDown = fopen("C:\\Users\\Admin\\Desktop\\raw_edgeDiagonalDown.dat", "rb");
    FILE *FileDiagonalUp = fopen("C:\\Users\\Admin\\Desktop\\raw_edgeDiagonalUp.dat", "rb");
    FILE *FileHorizontal = fopen("C:\\Users\\Admin\\Desktop\\raw_edgeHorizontal.dat", "rb");
    FILE *FileVertical = fopen("C:\\Users\\Admin\\Desktop\\raw_edgeVertical.dat", "rb");

    unsigned char DiagonalDown[Width][Height];
    unsigned char DiagonalUp[Width][Height];
    unsigned char Horizontal[Width][Height];
    unsigned char Vertical[Width][Height];
    
    fread(DiagonalDown, 1, Width * Height, FileDiagonalDown);
    fread(DiagonalUp, 1, Width * Height, FileDiagonalUp);
    fread(Horizontal, 1, Width * Height, FileHorizontal);
    fread(Vertical, 1, Width * Height, FileVertical);

    // Chia ma trận thành 64 phần và tính tổng từng phần

    unsigned char VectorDiagonalDown[] = {0};
    unsigned char VectorDiagonalUp[] = {0};
    unsigned char VectorHorizontal[] = {0};
    unsigned char VectorVertical[] = {0};
    unsigned char Vecto[256];
    // int partRows = Width / Parts;
    // int partCols = Height / Parts;
    chiaMaTran(DiagonalDown,VectorDiagonalDown);
    chiaMaTran(DiagonalUp,VectorDiagonalUp);
    chiaMaTran(Horizontal,VectorHorizontal);
    chiaMaTran(Vertical,VectorVertical);

    // Chuyển lần lượt giá trị của 4 mảng sang mảng duy nhất
    int currentIndex = 0;  

    for (int i = 0; i < Parts; ++i) {
            Vecto[currentIndex++] = VectorDiagonalDown[i];
    }
    for (int i = 0; i < Parts; ++i) {
            Vecto[currentIndex++] = VectorDiagonalUp[i];
            
    }
    for (int i = 0; i < Parts; ++i) {
            Vecto[currentIndex++] = VectorHorizontal[i];
    }
    for (int i = 0; i < Parts; ++i) {
            Vecto[currentIndex++] = VectorVertical[i];
    }

    
    // for (int i = 0; i < Parts*Parts; ++i) {
    //     printf("%d ", Vecto[i]);
    // }
    FILE *outputFileVector = fopen("C:\\Users\\Admin\\Desktop\\vector2.dat", "wb");

    for (int i = 0; i < Parts*Parts; ++i) {
            unsigned char binary = Vecto[i];
            fwrite(&binary, 1, 1, outputFileVector);
    }
    fclose(outputFileVector);
    fclose(FileDiagonalDown);
    fclose(FileDiagonalUp);
    fclose(FileHorizontal);
    fclose(FileVertical);
}


