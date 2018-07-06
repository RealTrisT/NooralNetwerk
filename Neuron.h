
/*  Precision: leave uncommented which precision to use  */
/*#define PRECISION_SINGLE*/
#define PRECISION_DOUBLE 

#if defined PRECISION_SINGLE
	#define PRECISION_S true
	#define PRECISION_D false
	typedef float fp;
#elif defined PRECISION_DOUBLE
	#define PRECISION_S false
	#define PRECISION_D true
	typedef double fp;
#endif

enum NeuronType{
	NType_Linear,
	NType_BinaryThreshold,
	NType_Rectifier,
	NType_Sigmoid,
	NType_StochasticBinary
};


class Neuron{
public:
	Neuron(){}
	~Neuron(){}
	virtual fp CalculateOutput();
	fp inputValue;
	fp outputValue;

};

class NeuronHiddenLayer : public Neuron{
public:
	struct Connection{
		Neuron* PrevLayerNeuronIndex;
		fp Weight;
	};

	const unsigned int connectionAmount;
	Connection* connections;

private:
	bool isConnectionListAllocated;

public:
	NeuronHiddenLayer(unsigned int ConAmount, Connection* Cons = 0);
	~NeuronHiddenLayer();
	fp CalculateInput();
};

class Neuron_Linear : public NeuronHiddenLayer{
public:
	Neuron_Linear(unsigned int ConAmount, Connection* Cons, fp M = 1, fp B = 1) : NeuronHiddenLayer(ConAmount, Cons), m(M), b(B){}
	fp m;			//slope
	fp b;			//bias
	fp CalculateOutput();
};

class Neuron_BinaryThreshold : public NeuronHiddenLayer{
public:
	Neuron_BinaryThreshold(unsigned int ConAmount, Connection* Cons, fp threshold = 1) : NeuronHiddenLayer(ConAmount, Cons), Threshold(threshold){}
	fp Threshold;
	fp CalculateOutput();
};