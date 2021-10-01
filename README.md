# Mobile-Classifier

So with the invention of [MobileNet](https://arxiv.org/pdf/1704.04861.pdf) series of CNN models, detection and classification tasks which required high-end hardware for speed and accuracy, were introduced to mobile hardware with limited computing resources. Consequently, with the help of these kind of models state-of-the-art performance was achieved even on cheaper hardware dev boards such as raspberry-pi and arduino. This idea of "mobile-classifier" follows the same intrinsic principles of Mobilenet based classifier with a small modification applied to it's end layer.  

The main goal which is intended to be achieved: attain faster inference time for mobile-classifier on Raspberry-Pi when compared with parametric MobileNet classifier. Please refer this page to understand the concept, the difference between mobile-classifier and parametric MobileNet classifier.

## Usage:

* Required OS: Linux(Raspbian for raspberry-pi or Ubuntu for x86)
* GCC and G++ version: 6.5 or higher
* Python: version 3.5 or higher
* Framework used for inferencing CNN model: [Caffe](https://caffe.berkeleyvision.org/)
* Image processing framework: [OpenCV](https://github.com/opencv/opencv)

### Installation and Execution on Ubuntu for x86 architecture:

* Firstly, it's recommended to have Ubuntu 16.04 to start installation process. It by default has gcc-5.4, hence please follow steps mentioned over [here](https://gist.github.com/zuyu/7d5682a5c75282c596449758d21db5ed) to change to gcc-6.5 .

* Install dependencies required to run Caffe and OpenCV frameworks.
```bash
sh install_deps.sh # Run this script to install dependencies at once.
```
* From here there are two ways. Either, one can opt for installing caffe from scratch and integrate it's executable layer files with the applicaton or simply download pre compiled executables and place them in lib folder. Both of these steps are mentioned below:

**Option 1: Build caffe from scratch*

1. Cloning and Building:
```bash
git clone https://github.com/rahulmangalampalli/caffe.git
cd caffe
make all && make distribute
```
If the above commands run without any error ,then caffe has been built successfully.

2. Integrating with Application:

```bash
git clone https://github.com/rahulmangalampalli/Mobile-Classifier.git
cd Mobile-Classifier
cp /path/to/your/caffe/distribute/lib/libcaffe.a /path/to/current/working/directory/lib
cd lib
ar x libcaffe.a
rm libcaffe
cd ..
mkdir build
cd build
sudo cmake ..
sudo make all
```
3. If these commands execute without any error, then a binary file called program will be created in build folder.

**Option 2: Get precompiled caffe executables*

* The precompiled executables for x86 architecture can found [here](https://drive.google.com/file/d/1Pa9fW72Qj0DTmq7w0O2hUxsfW1YgZBz4/view?usp=sharing). Download the tar files, extract all it's contents to Mobile-Classifier/lib. Then follow the steps mentioned below:

```bash
mkdir build
cd build
sudo cmake ..
sudo make all
```
* If these commands execute without any error, then a binary file called program will be created in build folder.

**Execution:**

* Execute the program binary from terminal as mentioned below:

```bash
./program
```
* Provide appropriate file paths for each and every label in the dataset.
* After training, the program will create two files ,namely labels.txt and train.knn .
* To inference, execute the program file again after training and this time choose **inference mode**. Provide image path to program to infer accoringly.

**Note: labels.txt and train.knn must be present in the same directory of execution while inferencing.**


## Credits:[Boilerplate](https://github.com/googlecreativelab/teachable-machine-boilerplate)  
[Teachable Machine](https://teachablemachine.withgoogle.com/)  

## This project was made in collaboration with IoTIoT.in, please visit their visit for more information:[link](http://iotiot.in/)
