# Order-Dithering-and-Halftoning-Inverse
Image halftoning is one of many techniques to convert a gray or color image to the dot-pattern image. 
Implemented a simple halftoning inverse method, which aims at reconstructing a continuous-tone image from halftone image of white and 
black dots. The image can either be black and white or colored. 

Ordered Dithereing: - 

Starting with gray-scale image, there are 0-255 integral levels. Compare pixel
values of each NxN block against the screening matrix, find the pixels of values 3
larger than their counterparts in the screening matrix, and change their values to
255. The rest pixels are assigned with a value of 0, which makes them to be black
dots. The pixel values are normalized as well. Repeat this process on each 8x8 block.
For color image processing, each channel is computed using a gray image halftoning method

Halftoning Inverse: -

Halftoning reversion is the problem of reconstructing continuous-tone images
from halftone images of white and black pixels. In general, the problem does not
have a unique solution, since halftoning is a many-to-one map from continuous-tone
images to binary ones. Program processes a dot-pattern halftoning
image in .bmp format and output a corresponding continuous-tone image.


