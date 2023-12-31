/////////////////////////////////////////////////////////////
// Author: Domenic Marcelli  R&D Team VT CRO
// filename: MotorControl.h
// Last Modified: 10/07/2023
// Description:  This the header file for the motor controls.
///////////////////////////////////////////////////////////// 


//Notes: Here is a sensor I found that using the pins https://github.com/roggenkamps/teensy-thermoled/blob/master/tempsens.c
// we have four motors


#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

#include <avr/io.h>
#include <avr/pgmspace.h>
#include "arduino_freertos.h"
#include "Active.h"

class MotorControl : public Active {

    public:

    MotorControl();

    //Sets the PID Params
    void Motor_setPIDParams();

    void Motor_pin_init();

    //Starts the motors
    void Motor_start();

    void dispatch();

    //sets the speed
    void Motor_setSpeed(int value);

    //sets the motor direction
    void Motor_setDirection(int direction, int delay);

    //pid loop
    void Motor_pidControlLoop();

    private:

    typedef struct{
    int motorId ;
    int encoderPos;
    int targetSpeed;
    int maxSpeed; 
    
    } _MotorStruct;

    typedef _MotorStruct MotorStruct;

    //These names are temporary.
    int motorOutputPin1;
    int motorOutputPin2;
    int motorOutputPin3;
    int motorOutputPin4;
};
//All the variables needed to control the motors


#endif