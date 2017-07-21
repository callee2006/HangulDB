This repository contains three sets of handwritten Hangul Datasets: PE92, SERI95, and HanDB.


* A Brief History of PE92, SERI95, and HanDB.

PE92 handwritten Hangul dataset was collected by POSTECH, funded by ETRI(www.etri.re.kr) in 1992. It has 2350 classes, each of which contains about 100 samples. SERI95 was collected by Korea University, funded by SERI (System Engineering Research Institute), which was merged with ETRI in 1997. SERI95 has 520 the most frequently used Hangul characters, each of which contains about 1000 samples.

Originally, ETRI had legal right on the two dataset. However, the two datasets were lost for many years. None of ETRI, POSTECH, or Korea Univ. preserved the two datasets. Fortunatelly, Prof. Injung Kim of Handong Global University kept a copy of the two handwritten Hangul datasets. ETRI kindly agreed that Handong Global University may open PE92 and SERI95 datasets to public. Up to my knowledge, PE92 and SERI95 are the only handwritten Hangul datasets publically available, and you can download them here.

The format of the two datasets are different from the original ones. In 1990's, KAIST AI lab converted them into other formats. Later, Prof. Injung Kim unified their formats into .HGU1 format, described below, and separated them into two groups: a training set containing 90% of samples, and a test set containing 10% of samples.

Unfortunatelly, neither of PE92 nor SERI95 is sufficient for practical applications: PE92 contains too few samples, while SERI95 contains too few classes. Therefore, Injung merged the two datasets and named it HanDB. HanDB contains 2350 classes. Among them, 520 classes has about 1000 samples, while other classes has about 100 samples.



* Reported results on PE92 and SERI95

Handwritten Hangul recognition was known as very difficult problem due to the abundance of confusing patterns and cursive writing style. Up to 2013, the best performances were merely 85.99% on PE92 and 93.71% on SERI95 [Park&Kim13]. However, Kim applied convolutional neural networks (CNN) to handwritten Hangul recognition for the first time, and achieved much superior results: 92.92% on PE92 and 95.96% on SERI95 [Kim15]. After that, he improved more by applying a hybrid learning algorithm[Kim16]. The best performances achived so far are 96.34% on SERI92 and 97.67% on SERI95, respectively.



* References
[Kim16] In-Jung Kim, Changbeom Choi and Sang-Heon Lee, Improving discrimination ability of convolutional neural networks by hybrid learning, International 
Journal on Document Analysis and Recognition, 2016.

[Kim15] In-Jung Kim and Xiaohui Xie, "Handwritten Hangul Recognition using Deep Convolutional Neural Networks," International Journal on Document Analysis and Recognition, vol.18, issue 1, pp.1-13, March 2015.

[Park&Kim13] Gyu-Ro Park, In-Jung Kim, and Cheng-Lin Liu, "An evaluation of statistical methods in handwritten Hangul recognition," International Journal on Document Analysis and Recognition, vol.16, issue 3, pp.273-283, Sep.2013.



* HGU1 file format
.hgu1 file contains multiple character images. It is composed of a file header (8 bytes), followed by a series of images (variable length).

&lt hgu1 file> := &lt file header> &lt image1> &lt image2> &lt image3> ...
&lt file header> := "HGU1    " (8 bytes)

&lt imageN> := &lt image header> &lt image data>
&lt image header> := &lt code (2 bytes)> &lt width (1 byte)> &lt height(1 byte)> &lt reserved(2 bytes)>
&lt image data> := 256 gray data (width * height bytes, row-major format)



DisplayHGU1.cpp contains C/C++ functions to read and write images in HGU1 format.



God bless you!

Prof. Injung Kim (ijkim@handong.edu, deeplearning.handong.edu or pro.handong.edu/callee),
School of Computer Science and Eletrical Engineering
Handong Global University (www.handong.edu).

