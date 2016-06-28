//
//  mdStarbust.hpp
//  Pupilware
//
//  Created by Chatchai Wangwiwattana on 5/25/16.
//  Copyright © 2016 Chatchai Wangwiwattana. All rights reserved.
//

#ifndef MDSTARBURSTNEO_HPP
#define MDSTARBURSTNEO_HPP

#include "IPupilAlgorithm.hpp"

namespace pw {

    class MDStarbustNeo : public IPupilAlgorithm {

    public:
        MDStarbustNeo( const std::string& name );
        virtual ~MDStarbustNeo();

        virtual void init() override ;

        virtual PWPupilSize process( const cv::Mat src, const PWFaceMeta &meta ) override;

        virtual void exit() override ;
        
        const cv::Mat& getDebugImage() const;

    protected:


        // Maximum iteration of processing starbust algorithm
        const unsigned int STARBURST_ITERATION = 5;


        // Minimum number of rays before doing RANSAC circle fit algorithm
        const unsigned int MIN_NUM_RAYS = 5;


        // Minimum number of points before doing Ellipse fit algorithm
        const unsigned int MIM_NUM_INLIER_POINTS = 5;


        // It used to convert a trackbar's INT to Float
        const float precision = 1000;


        // The different seed intensity to the edge threshold.
        // It's used to stop Starbust algorithm to walk forward.
        int threshold;


        // Number of rays
        int rayNumber;


        // Degree from the top of circle
        // it is designed for avoid eyelash shadow
        int degreeOffset;


        // Simple linear primer.
        // It's used to improve a reflection problem in pupils.
        int primer;


        // Just a window name for debuging
        std::shared_ptr<CVWindow> window;
        
        // Debug Image
        cv::Mat debugImage;


        // Create rays that walk from center of the eyes
        void createRays(std::vector<cv::Point2f> &rays) const;


        // Find edge points
        void findEdgePoints(cv::Mat grayEye,
                            const cv::Point &startingPoint,
                            const std::vector<cv::Point2f> &rays,
                            std::vector<cv::Point2f> &outEdgePoints,
                            cv::Mat debugColorEye) const;



        bool isValidEllipse(const cv::RotatedRect &theEllipse) const;



        // Cost function to predict if the pixel an edge or reflection
        virtual float getCost(int step, int eyeWidth, int thresholdValue) const;



        float findPupilSize(const cv::Mat &colorEyeFrame,
                            cv::Point eyeCenter,
                            cv::Mat &debugImg) const;
    };
}

#endif /* MDSTARBURSTNEO_HPP */
