#include <iostream>
#include <cstdlib>

#include <vector>

// Librerías de OpenCV 4
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

void erosion(Mat gris) {
    namedWindow("Erosion", WINDOW_AUTOSIZE);
    Mat erosion;
    int k = 47;
    Mat estructura = getStructuringElement(MORPH_CROSS, Size(k,k));
    erode(gris,erosion,estructura);
    imshow("Erosion", erosion);
}
void dilatacion(Mat gris) {
    namedWindow("Dilatacion", WINDOW_AUTOSIZE);
    Mat dilatacion;
    int k = 47;
    Mat estructura = getStructuringElement(MORPH_CROSS, Size(k, k));
    dilate(gris,dilatacion,estructura);
    imshow("Dilatacion", dilatacion);
}

Mat topHat(Mat gris) {
    int k =37;
    Mat top;
    Mat estructura = getStructuringElement(MORPH_CROSS, Size(k,k));

    morphologyEx(gris, top, MORPH_TOPHAT, estructura);

    return top;
}
Mat blackHat(Mat gris) {
    int k = 37;
    Mat black;
    Mat estructura = getStructuringElement(MORPH_CROSS, Size(k, k));

    morphologyEx(gris, black, MORPH_BLACKHAT, estructura);

    return black;
}
int main(int argc, char* argv[]) {

	Mat imagen = imread("C:/Users/javie/Desktop/8vo/Vision_Computador/Boletin2/prueba3.png");
	namedWindow("Imagen", WINDOW_AUTOSIZE);
    namedWindow("Gris", WINDOW_AUTOSIZE);
    namedWindow("Top Hat", WINDOW_AUTOSIZE);
    namedWindow("Black Hat", WINDOW_AUTOSIZE);
    Mat gris;
    cvtColor(imagen, gris, COLOR_BGR2GRAY);
    Mat black, top,resta,suma;
    erosion(gris);
    dilatacion(gris);
    top=topHat(gris);
    black=blackHat(gris);

    resta=abs(top - black);
    add(gris, resta,suma);

    imshow("Imagen", imagen);
    imshow("Gris", gris);
    imshow("Black Hat", black);
    imshow("Top Hat", top);
    imshow("Resta", resta);
    imshow("Suma", suma );


    waitKey(0);

    return 0;
}