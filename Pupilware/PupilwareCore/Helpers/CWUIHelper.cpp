//
// Created by Chatchai Wangwiwattana on 5/26/16.
//

#include "CWUIHelper.hpp"

#include "simpleGraph/GraphUtils.h"
#include "CVWindow.hpp"

namespace cw {


    void showGraph(const std::string& name,
                   const std::vector<float> &dataSrc,
                   int delayInMilliSec,
                   cv::Scalar color) {


        setCustomGraphColor(static_cast<int>(color[0]),
                            static_cast<int>(color[1]),
                            static_cast<int>(color[2]));
        
        showFloatGraph(name.c_str(),
                       dataSrc.data(),
                       static_cast<int>(dataSrc.size()),
                       delayInMilliSec);
    }

    int showImage(const std::string& name, const cv::Mat img, int delayInMilliSec) {
        
        cv::namedWindow(name, CV_WINDOW_NORMAL | CV_WINDOW_KEEPRATIO);
        cv::imshow(name, img);
        return cv::waitKey(delayInMilliSec);
        
    }

    std::shared_ptr<pw::CVWindow> createWindow( const std::string& winName){
        return std::shared_ptr<pw::CVWindow>(new pw::CVWindow(winName));
    }

    //----------------------------------------------------------------------------
    //  Simple OpenCV Warper
    //----------------------------------------------------------------------------

    void namedWindow( const std::string& winName, int flag ){

        cv::namedWindow(winName, flag);
    }


    void createTrackbar( const std::string& barName,
                         const std::string& windowName,
                         int& value, int max,
                         cv::TrackbarCallback callback ,
                         void* userData  ){

        cv::createTrackbar( barName, windowName, &value, max, callback, userData);
    }


    void imshow(const std::string& winName, cv::InputArray mat){

        cv::imshow(winName, mat);
    }


    int waitKey(int delay){
        return cv::waitKey(delay);
    }

}