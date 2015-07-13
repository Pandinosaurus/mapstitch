#ifndef MAPSTITCH_H
#define MAPSTITCH_H

#include <stdio.h>
#include <math.h>
#include <opencv/cv.h>

using namespace cv;
using namespace std;

class StitchedMap
{
public:
  StitchedMap(Mat &im1, Mat &im2, float max_distance=5.);
  ~StitchedMap();

  Mat get_debug();
  Mat get_stitch();

  void printDebugOutput();
  bool isValid();

  Mat estimateHomographyRansac(const vector<DMatch>& matches,
                                const vector<KeyPoint> dest,
                                const vector<KeyPoint> input);

  Mat H; // transformation matrix
  double rot_deg,rot_rad,transx,transy,scalex,scaley;

protected:

  Mat image1, image2,
      dscv1, dscv2;
  bool is_valid;

  vector<KeyPoint> kpv1,kpv2;
  vector<KeyPoint> fil1,fil2;
  vector<Point2f>  coord1,coord2;
  vector<DMatch>   matches;
  vector<DMatch>   matches_filtered;

};

#endif // MAPSTITCH_H
