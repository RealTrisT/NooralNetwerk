#include <stdio.h>
#include <stdlib.h>

#include "Neuron.h"

Neuron input[2] = {											//2 input neurons
	Neuron(), Neuron()
};
NeuronHiddenLayer::Connection inputToLayer1Neuron0[2] = {	//2 connections between input layers and first neuron of first hidden layer
	{&input[0], 1},  {&input[1], 1}
};
NeuronHiddenLayer::Connection inputToLayer1Neuron1[2] = {	//2 connections between input layers and second neuron of first hidden layer
	{&input[0], -1}, {&input[1], -1}
};
Neuron_BinaryThreshold layer1[2] = {						//first hidden layer
	Neuron_BinaryThreshold(2, inputToLayer1Neuron0, 0.5),
	Neuron_BinaryThreshold(2, inputToLayer1Neuron1, -1.5)
};
NeuronHiddenLayer::Connection inputToLayer2[2] = {			//connections between first and second hidden layers
	{&layer1[0], 1},
	{&layer1[1], 1}
};	
Neuron_BinaryThreshold layer2[1] = {						//second hidden layer
	Neuron_BinaryThreshold(2, inputToLayer2, 1.5)
};



int main(int argc, char const *argv[]){
	printf("xor (input A and B, will output A^B):\n");
	while(1 != 2){
		scanf((PRECISION_D)?"%lf %lf":"%f %f", &input[0].outputValue, &input[1].outputValue);

		layer1[0].CalculateInput();
		layer1[0].CalculateOutput();

		layer1[1].CalculateInput();
		layer1[1].CalculateOutput();

		layer2[0].CalculateInput();
		layer2[0].CalculateOutput();

		printf("%d\n", (char)layer2[0].outputValue);
	}	
	return 0;
}