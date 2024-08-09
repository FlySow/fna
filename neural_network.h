#ifndef __NEURAL_NETWORK__
#define __NEURAL_NETWORK__

#include <matrix.h>

typedef struct s_layer {
	int size;
	int prev_size;
	matrix weights;
	matrix bias;
	double (*activ)(double);
	matrix temp_neurons;
} layer;


typedef struct s_neural_network {
	int size;
	int input_size;
	layer* layers;
} neural_network;


neural_network nncreate_empty(int input_size);

neural_network nnadd_layer(neural_network net, int size, double (*activation)(double));

neural_network nnprint(neural_network net);


#endif
	
