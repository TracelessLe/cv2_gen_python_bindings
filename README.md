# Introduction
Use OpenCV pybind tools (cv2.cpp & gen2.py ...) to generate a python binding use OpenCV Mat as input parameters.

![issueBadge](https://img.shields.io/github/issues/TracelessLe/cv2_gen_python_bindings)   ![starBadge](https://img.shields.io/github/stars/TracelessLe/cv2_gen_python_bindings)   ![repoSize](https://img.shields.io/github/repo-size/TracelessLe/cv2_gen_python_bindings)  ![lastCommit](https://img.shields.io/github/last-commit/TracelessLe/cv2_gen_python_bindings) 

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
holes.jpg

<img src="https://raw.githubusercontent.com/TracelessLe/cv2_gen_python_bindings/master/build/holes.jpg" width="450" height="auto">

Originalimage.png

<img src="https://raw.githubusercontent.com/TracelessLe/cv2_gen_python_bindings/master/build/Originalimage.png" width="450" height="auto">

PythonModuleFunctionExample.png

<img src="https://raw.githubusercontent.com/TracelessLe/cv2_gen_python_bindings/master/build/PythonModuleFunctionExample.png" width="450" height="auto">

PythonModuleClassExample.png

<img src="https://raw.githubusercontent.com/TracelessLe/cv2_gen_python_bindings/master/build/PythonModuleClassExample.png" width="450" height="auto">

# Appreciation
Thanks for spmallick for his inspiring [learnopencv](https://github.com/spmallick/learnopencv/tree/master/pymodule).
