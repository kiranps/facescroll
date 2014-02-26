/*
#############################################
Created by Kiran ps
pskirann@gmail.com
#############################################
*/

#include<opencv2/opencv.hpp>
#include<stdlib.h>

using namespace std;
using namespace cv;

CascadeClassifier faceCade;
String faceCascadeName = "/home/kiran/repo/cpp/fa/haarcascade_frontalface_alt.xml";

int main() {

    VideoCapture cap(0);
    Mat camFrames, grayFrames;
    vector<Rect> faces;

    int k=0;
    int posx,posy;
    int d=20;
    int x,y;
    int up=0,down=0;

    if( !faceCade.load( faceCascadeName ) )
    {
        return 0;
    }


    while (1)
    {
        cap >> camFrames;
        cvtColor(camFrames, grayFrames, CV_BGR2GRAY);
        equalizeHist(grayFrames, grayFrames);

        faceCade.detectMultiScale(grayFrames, faces, 1.1, 2, 0, Size(180, 180));

        x=faces[0].x+(faces[0].width/2);
        y=faces[0].y+(faces[0].height/2);


        if(k == 0)
        {
            posx = x;
            posy = y;
            k=1;
        }
        else
        {
            if(y < posy-d)
            {
                if(up<=15)
                {
                    cout<<"\nup";
                    system("xte 'key Up'");
                }
                else if (up>15 && up<30)
                {
                    cout<<"\nup2";
                    system("xte 'key Up' 'key Up'");
                }
                else
                {
                    cout<<"\nup3";
                    system("xte 'key Up' 'key Up' 'key Up'");
                }
            up++;
            close=0;
            down=0;
            }
            else if(y > posy+d)
            {
                if(down<=15)
                {
                    cout<<"\ndown";
                    system("xte 'key Down'");
                }
                else if (down>15 && down<30)
                {
                    cout<<"\ndown2";
                    system("xte 'key Down' 'key Down' 'key Down'");
                }
                else
                {
                    cout<<"\ndown3";
                    system("xte 'key Down' 'key Down' 'key Down' 'key Down' 'key Down' 'key Down' 'key Down'");
                }
             down++;
             close=0;
             up=0;
            }
            else
            {
                up=down=0;
            }
        }
    }
}

