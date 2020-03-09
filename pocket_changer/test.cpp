#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

vector<string> colors = {"red", "yellow", "green", "blue", "pink"};
vector<int> hueVal = {180, 30, 60, 120, 160};
unsigned char colorShift(unsigned char h, int left, int middle, int right);
unsigned char blueShift(unsigned char h, int hue_shift);
unsigned char greenShift(unsigned char h, int hue_shift);
unsigned char redShift(unsigned char h, int hue_shift);
int findColor(string col);

int main(int argc, char *argv[])

{

    //open file
    Mat img = imread(argv[1]); // loads image from first argument
    int leftColor = findColor(argv[2]);
    int middleColor = findColor(argv[3]);
    int rightColor = findColor(argv[4]);


    Mat hsv;
    cvtColor(img, hsv, COLOR_BGR2HSV);

    for (int j = 0; j < img.rows; j++)
    {
        for (int i = 0; i < img.cols; i++)
        {
            unsigned char h = hsv.at<Vec3b>(j, i)[0];
            h = colorShift(h, leftColor, middleColor, rightColor);
            hsv.at<Vec3b>(j, i)[0] = h;
        }
    }

    //saveFile
    Mat output;
    cvtColor(hsv, output, COLOR_HSV2BGR);
    string fileName = "/home/jtwalton/lax-squad/express-api/tmtlax_api/output/" + colors[leftColor] + "_" + colors[middleColor] + "_" + colors[rightColor] + ".jpg";
    imwrite(fileName, output);
    cout << fileName;
    return 0;
}

unsigned char colorShift(unsigned char h, int left, int middle, int right)
{

    if (h < 150 && h > 80)
    {
        h = blueShift(h, hueVal[left]);
    }

    if (h < 90 && h > 30)
    {
        h = greenShift(h, hueVal[middle]);
    }

    if (h < 30 || h > 150)
    {
        h = redShift(h, hueVal[right]);
    }

    return h;
}

unsigned char blueShift(unsigned char h, int hue_shift)
{
    if (h + hue_shift > 120)
        h = (h + hue_shift) - 120;
    else
        h = h + hue_shift;

    return h;
}

unsigned char greenShift(unsigned char h, int hue_shift)
{
    if (h + hue_shift > 60)
        h = (h + hue_shift) - 60;
    else
        h = h + hue_shift;

    return h;
}

unsigned char redShift(unsigned char h, int hue_shift)
{
    if (h + hue_shift > 180)
        h = (h + hue_shift) - 180;
    else
        h = h + hue_shift;

    return h;
}

int findColor(string col)
{
    for (int i = 0; i < colors.size(); i++)
    {
        if (col == colors[i])
        {
            return i;
        }
    }
    return -1;
}
