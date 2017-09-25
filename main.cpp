
#include "slic.h"

using namespace cv;
using namespace std;


int main(int argc, char *argv[]) {
    /* Load the image and convert to Lab colour space. */

    Mat *image, *lab_image;
    Mat srcImage,labImage;

    srcImage = imread("tree.jpg");
    int width = srcImage.cols;
    int height = srcImage.rows;

    cvtColor(srcImage,labImage,CV_BGR2Lab);

    image = &srcImage;
    lab_image = &labImage;


    /* Yield the number of superpixels and weight-factors from the user. */
    int w = image->cols, h = image->rows;
    int nr_superpixels = 300;

    int nc = 80;

    double step = sqrt((w * h) / (double) nr_superpixels);

    /* Perform the SLIC superpixel algorithm. */
    Slic slic;

    slic.generate_superpixels(lab_image, step, nc);

    slic.create_connectivity(lab_image);

    /* cluster superpixels */
//    slic.colour_with_cluster_means(image);

    /* Display the contours and show the result. */
    slic.display_contours(image, CV_RGB(255,0,0));

    imshow("result", *image);
    waitKey(0);

    return 0;
}
