#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "Galaxies.h"
#include "Stack.h"
using namespace cv;
using namespace std;

// Main for black and white.
int main(int argc, char **argv)
{
    Mat image;

    const string path = samples::findFile("");          // enter path here.
  
    image = imread(path);
    cvtColor(image, image, COLOR_BGR2GRAY);         // Convert image to grayscale if not already.

    stack1 s;                                   // using stack to count total number of objects. Queue can also be used.
    //Queue q;
    string destPath = "";                       // Enter path to store generated images.

    cout << "Total number of objects are " << find_objects(image, s, destPath) << '\n';
}
