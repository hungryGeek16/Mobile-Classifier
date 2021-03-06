#include <iostream> //for std i/o operations in c++
#include <stdio.h> //for std i/o operations in c++
#include <string> //for dealing with strings
#include "caffe/common.hpp"   // re-declaration of the header file for dealing with common operations such as reading and managing blobs
#include "caffe/layers/input_layer.hpp"  // re-declaration of the header file to register with input layer in caffe
#include "caffe/layers/dropout_layer.hpp"  // re-declaration of the header file to register with dropout layer in caffe
#include "caffe/layers/conv_layer.hpp"  // re-declaration of the header file to register with conv layer in caffe
#include "caffe/layers/relu6_layer.hpp"  // re-declaration of the header file to register with relu6 layer in caffe
#include "caffe/layers/slice_layer.hpp" // re-declaration of the header file to register with slice layer in caffe
#include "caffe/layers/pooling_layer.hpp"  // re-declaration of the header file to register with pooling layer in caffe
#include "caffe/layers/batch_norm_layer.hpp" // re-declaration of the header file to register with batchnorm layer in caffe
#include "caffe/layers/scale_layer.hpp" // re-declaration of the header file to register with scale layer in caffe
#include "caffe/layers/bias_layer.hpp" // re-declaration of the header file to register with bias layer in caffe

namespace caffe  
{  
  
    extern INSTANTIATE_CLASS(InputLayer);  // Register input layer
    extern INSTANTIATE_CLASS(DropoutLayer);  // Register dropout layer
    extern INSTANTIATE_CLASS(ConvolutionLayer); // Register convolution layer
    REGISTER_LAYER_CLASS(Convolution); 
    extern INSTANTIATE_CLASS(PoolingLayer); 
    REGISTER_LAYER_CLASS(Pooling);   
    extern INSTANTIATE_CLASS(SliceLayer); //Register slice layer  
    extern INSTANTIATE_CLASS(BatchNormLayer); //Register batchnorm layer
    extern INSTANTIATE_CLASS(ScaleLayer); //Register scale layer
    extern INSTANTIATE_CLASS(BiasLayer); //Register bias layer
    extern INSTANTIATE_CLASS(ReLU6Layer);   //Register relu6 layer
}  


using namespace std;
using namespace cv;
using namespace cv::ml;

struct classInfo{
   int classid;
   std::string classname;
   std::string imageset_location;
};


class Classify{ // declaration of class classify
public:
    Classify(); //constructor
    ~Classify(); //destructor

	std::vector<classInfo>cls;
    int counter=0;
    Ptr<KNearest> trainedModel;

    std::string infer(std::string data_path);
    void loadModel(string knn_path="train.knn");
    std::string exportTrainedModel();
    void trainModel(vector<classInfo>cls);
    void listClasses(vector<classInfo>n);
    vector<classInfo> addClass(std::string classname, std::string imageset_location);


};

