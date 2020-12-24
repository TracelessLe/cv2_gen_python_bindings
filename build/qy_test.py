import cv2
import sys
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

