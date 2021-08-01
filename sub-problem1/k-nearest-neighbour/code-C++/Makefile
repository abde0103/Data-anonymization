EIGEN=/usr/local/eigen-3.3.7
ANN_INCLUDE=/usr/local/ann-1.1.2/include
ANN_LIB=/usr/local/ann-1.1.2/lib

all: knn_classifier

Dataset.o: Dataset.cpp
	g++ -c -std=c++11 -O2 -Wall -Wextra Dataset.cpp

Classification.o: Classification.cpp
	g++ -c -std=c++11 -O2 -I$(ANN_INCLUDE) -Wall -Wextra Classification.cpp
	
KnnClassification.o: KnnClassification.cpp
	g++ -c -std=c++11 -O2 -I$(ANN_INCLUDE) -Wall -Wextra KnnClassification.cpp	

ConfusionMatrix.o: ConfusionMatrix.cpp
	g++ -c -std=c++11 -O2 -I$(ANN_INCLUDE) -Wall -Wextra ConfusionMatrix.cpp	

RandomProjection.o: RandomProjection.cpp
	g++ -c -std=c++11 -O2 -I$(EIGEN) -std=c++11 -Wall -Wextra RandomProjection.cpp	

knn_classifier: knn_classifier.cpp ConfusionMatrix.o KnnClassification.o Classification.o Dataset.o
	g++ -std=c++11 -O2 -I$(EIGEN) -I$(ANN_INCLUDE) -Wall -Wextra knn_classifier.cpp ConfusionMatrix.o KnnClassification.o Classification.o Dataset.o -o knn_classifier -L$(ANN_LIB) -lANN 


.PHONY: all clean

clean:
	rm -f *.o
	rm -f knn_classifier
