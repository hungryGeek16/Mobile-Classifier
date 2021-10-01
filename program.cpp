#include <opencv2/core/core.hpp>     
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/ml.hpp>

#include <iostream>
#include <stdio.h> 
#include <string>
#include <vector>

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
    void infer_video();
    void loadModel(string knn_path="train.knn");
    std::string exportTrainedModel();
    void trainModel(vector<classInfo>cls);
    void listClasses(vector<classInfo>n);
    vector<classInfo> addClass(std::string classname, std::string imageset_location);


};

int main(){
    // Main program will call all the functions
    Classify ic;
    int x;
    std::cout << "\nPlease choose 0 for training mode and 1 for inference mode:";
    cin >> x;
    if (x == 0){
    	std::cout<<"\nStart executing";
    	int n;
    	std::cout<<"\nHow many classes are there?: ";
    	std::cin>>n;
    	vector<classInfo>classinfo;
    	for(int i=0;i<n;i++)
    	{
        	std::string classn,iloc;
		std::cout<<"\nEnter class name: ";
    		std::cin>>classn;
		std::cout<<"\nEnter imagenet location: ";
    		std::cin>>iloc;
		classinfo = ic.addClass(classn,iloc);
    	}
    //****************List classes section***************
    	ic.listClasses(classinfo);
    //****************trainModel section*****************
    	ic.trainModel(classinfo);
    	cout<<endl;
    }
    else if(x==1){
    //****************exportModel section****************
    string path = ic.exportTrainedModel();
    std::cout<<"\nModel Path: "<<path;
    //****************loadModel section******************
    ic.loadModel();
    //****************Inference section******************

    std::string label;
    std::cout << "\nPlease enter image path for testing:";
    cin >> label;
    cout << "\nThe class of this image is: " << ic.infer(label) << endl; //show the image class
  }
    else
    cout << "Wrong input for mode. Terminating..." <<endl;
}

