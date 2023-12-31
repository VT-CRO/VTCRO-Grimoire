#ifndef PID_H
#define PID_H

typedef struct{
	float kP;
	float kI;
	float kD;
	float EpsilonInner;
	float EpsilonOuter;
	float dInner;
	float dOuter;
	float sigma;
	float lastValue;
	float lastTarget;
	unsigned long lastTime;
	float LastSetPoint;
} PID;

extern PID pidInit(float fKP, float fKI, float fKD, float fEpsilonInner, float fEpsilonOuter,float dInner, float dOuter);
extern float pidCalculate(PID pid, float fSetPoint, float fProcessVariable);

#endif
