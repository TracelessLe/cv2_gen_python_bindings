# Introduction
Use OpenCV pybind tools (cv2.cpp & gen2.py ...) to generate a python binding use OpenCV Mat as input parameters.

# Guide
1. python3 gen2.py build
2. generate python binding
```
g++ -shared -rdynamic -g -O3 -Wall -fPIC \
qy.cpp src/qymodule.cpp \
-DMODULE_STR=qy -DMODULE_PREFIX=pyopencv \
-DNDEBUG -DPY_MAJOR_VERSION=3 \
`pkg-config --cflags --libs opencv` \
`/root/miniconda3/envs/pytorch1.6/bin/python3.7m-config --includes --ldflags` \
-I . -I/root/miniconda3/envs/pytorch1.6/lib/python3.7/site-packages/numpy/core/include \
-L`/root/miniconda3/envs/pytorch1.6/bin/python3.7m-config --exec-prefix`/lib \
-Ibuild \
-fno-lto \
-o build/qy.so
```
3. python import and use.

# Use in Python

``` python
import sys
import cv2
#sys.path.append('build')
import qy

im = cv2.imread('holes.jpg', cv2.IMREAD_GRAYSCALE)
imfilled = im.copy()
qy.fillHoles(imfilled)

filters = qy.Filters() 
imedge = filters.edge(im)


cv2.imwrite("Originalimage.png", im)
cv2.imwrite("PythonModuleFunctionExample.png", imfilled)
cv2.imwrite("PythonModuleClassExample.png", imedge)
```



# Appreciation
Thanks for spmallick for his inspiring [learnopencv] (https://github.com/spmallick/learnopencv/tree/master/pymodule).