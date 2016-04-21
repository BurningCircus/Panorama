//Panorama.h
//Zach Hummel
//11/5/2015

//An audio plugin allowing panning of stereo audio tracks.

//This plugin implements three panning algorithms:
// - Linear crossfade
// - Equal power
// - Speaker to speaker

//It also allows for a custom pan law to be set by the user.

//Includes and Definitions
#include <math.h>
#include <stdlib.h>
#include <cmath>
#define PI 3.14159265

class Panorama {
public:
	//Constructor/Destructor
	Panorama();
	~Panorama();

	//Other declarations
	enum Algorithm : int { LINEAR_CROSSFADE = 0, EQUAL_POWER, SPEAKER_TO_SPEAKER };

	//Getters/Setters
	int getPan() {
		return m_pan;
	}
	
	float getPanLaw() {
		return m_panLaw;
	}

	Algorithm getAlgorithm() {
		return m_algorithm;
	}

	bool panLawEnabled() {
		return m_panLawEnabled;
	}

	void setPan(int pan);
	void setPanLaw(float panLaw);
	void setAlgorithm(Algorithm algorithm);
	void setPanLawEnabled(bool panLawEnabled);

	//Use functions
	void clockProcess(float *leftSample, float *rightSample);

private:
	int m_pan; //-100 <= m_pan <= 100 where 0 is centrally panned
	float m_panLaw;
	bool m_panLawEnabled;
	Algorithm m_algorithm;
};