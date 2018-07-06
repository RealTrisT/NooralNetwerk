#include <stdlib.h>
#include "Neuron.h"

fp Neuron::CalculateOutput(){
	return outputValue = inputValue;
}

NeuronHiddenLayer::NeuronHiddenLayer(unsigned int ConAmount, Connection* Cons) : connectionAmount(ConAmount), connections(Cons){
	if(isConnectionListAllocated = (!connections)){
		connections = (Connection*)malloc(sizeof(Connection) * connectionAmount);
}	}
NeuronHiddenLayer::~NeuronHiddenLayer(){
	if(isConnectionListAllocated){
		free((void*)connections);
}	}
fp NeuronHiddenLayer::CalculateInput(){
	inputValue = 0;
	for (int i = 0; i < connectionAmount; ++i){
		inputValue += connections[i].PrevLayerNeuronIndex->outputValue * connections[i].Weight;
	}
	return inputValue;
}


fp Neuron_Linear::CalculateOutput(){
	return outputValue = inputValue*m + b;
}

fp Neuron_BinaryThreshold::CalculateOutput(){
	return outputValue = (fp)(inputValue >= Threshold);
}