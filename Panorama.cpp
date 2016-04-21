//Panorama.cpp
//Zach Hummel
//11/5/15

//An audio plugin allowing panning of stereo audio tracks.

//This plugin implements three panning algorithms:
// - Linear crossfade
// - Equal power
// - Speaker to speaker

//It also allows for a custom pan law to be set by the user.

//Includes
#include "Panorama.h"

//Constructor
Panorama::Panorama() {
	setPan(0); //Set to central pan
	setPanLaw(3.0); //Set to 3db pan law (the default in most consoles and DAWs)
	setAlgorithm(Panorama::Algorithm::EQUAL_POWER); //Set to equal power panning
	setPanLawEnabled(true); //Turn on the pan law
}

//Destructor
Panorama::~Panorama() {}

//Getters/Setters
void Panorama::setPan(int pan) {
	if(pan > 100) {
		pan = 100;
	}
	if(pan < -100) {
		pan = -100;
	}

	m_pan = pan;
}

void Panorama::setPanLaw(float panLaw) {
	m_panLaw = panLaw;
}

void Panorama::setAlgorithm(Panorama::Algorithm algorithm) {
	m_algorithm = algorithm;
}

void Panorama::setPanLawEnabled(bool panLawEnabled) {
	m_panLawEnabled = panLawEnabled;
}

//Use functions
void Panorama::clockProcess(float *leftSample, float *rightSample) {
	switch(getAlgorithm()) {
	    
	    case Algorithm::LINEAR_CROSSFADE:
	    {
		    //Perform linear crossfade panning.
		    *leftSample = *leftSample * ((getPan() - 100.0) / -200.0);
		    *rightSample = *rightSample * ((getPan() + 100.0) / 200.0);
		    break;
	    }
	    case Algorithm::EQUAL_POWER:
	    {
		    //Perform equal power panning.
		    float angle = (getPan() + 100.0) / 200.0 * (PI/2.0);
		    *leftSample = *leftSample * cos(angle);
		    *rightSample = *rightSample * sin(angle);
		    break;
	    }	
	    case Algorithm::SPEAKER_TO_SPEAKER:
	    {
		    //Perform speaker to speaker panning.
		    //There is a dramatic assumption here that the listener's speakers are 
		    //  placed in an eqilateral triangle with relation to the listening position.
		    //It makes the calculations so much simpler.
		    //This is an original algorithm which uses a scaling technique to compensate
		    //  for the "radius effect" of equal-power panning.
		
		    //Equal-power panning
		    float angle = (getPan() + 100.0) / 200.0 * (PI/2.0);
		    *leftSample = *leftSample * cos(angle);
		    *rightSample = *rightSample * sin(angle);

		    //Apply custom scaling
		    float p = abs(getPan()) / (100 * sqrt(3));
		    float x = 1 / cos(atan(p));
		    float g = 10 * log10(pow((1/x), 2));
		    *leftSample = *leftSample * sqrt(pow(10, (.1 * g)));
		    *rightSample = *rightSample * sqrt(pow(10, (.1 * g)));
		    break;
	    }
	}

	if(panLawEnabled()) {
		//Apply the custom pan law.
		float dB = (100-abs(getPan())) * (getPanLaw() / 100);
		*leftSample = *leftSample * (1 / sqrt(pow(10, (.1 * dB))));
		*rightSample = *rightSample * (1 / sqrt(pow(10, (.1 * dB))));
	}
}