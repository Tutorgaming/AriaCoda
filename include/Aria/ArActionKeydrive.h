/*
Adept MobileRobots Robotics Interface for Applications (ARIA)
Copyright (C) 2004-2005 ActivMedia Robotics LLC
Copyright (C) 2006-2010 MobileRobots Inc.
Copyright (C) 2011-2015 Adept Technology, Inc.
Copyright (C) 2016-2018 Omron Adept Technologies, Inc.

     This program is free software; you can redistribute it and/or modify
     it under the terms of the GNU General Public License as published by
     the Free Software Foundation; either version 2 of the License, or
     (at your option) any later version.

     This program is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
     GNU General Public License for more details.

     You should have received a copy of the GNU General Public License
     along with this program; if not, write to the Free Software
     Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA


*/
#ifndef ARACTIONKEYDRIVE_H
#define ARACTIONKEYDRIVE_H

#include "Aria/ariaTypedefs.h"
#include "Aria/ArAction.h"
#include "Aria/ArFunctor.h"

class ArRobot;

/// This action will use the keyboard arrow keys for input to drive the robot
/// @ingroup ActionClasses
class ArActionKeydrive : public ArAction
{
public:
  /// Constructor
 AREXPORT ArActionKeydrive(const char *name = "keydrive",
			   double transVelMax = 400,
			   double turnAmountMax = 24,
			   double velIncrement = 25,
			   double turnIncrement = 8);
  //AREXPORT virtual ~ArActionKeydrive();
  AREXPORT virtual ArActionDesired *fire(ArActionDesired currentDesired) override;
  /// For setting the maximum speeds
  AREXPORT void setSpeeds(double transVelMax, double turnAmountMax);
  /// For setting the increment amounts
  AREXPORT void setIncrements(double velIncrement, double turnIncrement);
  AREXPORT virtual ArActionDesired *getDesired() override { return &myDesired; }
#ifndef SWIG
  AREXPORT virtual const ArActionDesired *getDesired() const override 
                                                        { return &myDesired; }
#endif
  AREXPORT virtual void setRobot(ArRobot *robot);
  AREXPORT virtual void activate();
  AREXPORT virtual void deactivate();
  /// Takes the keys this action wants to use to drive
  AREXPORT void takeKeys();
  /// Gives up the keys this action wants to use to drive
  AREXPORT void giveUpKeys();
  /// Internal, callback for up arrow
  AREXPORT void up();
  /// Internal, callback for down arrow
  AREXPORT void down();
  /// Internal, callback for left arrow
  AREXPORT void left();
  /// Internal, callback for right arrow
  AREXPORT void right();
  /// Internal, callback for space key
  AREXPORT void space();

protected:
  ArFunctorC<ArActionKeydrive> myUpCB;
  ArFunctorC<ArActionKeydrive> myDownCB;
  ArFunctorC<ArActionKeydrive> myLeftCB;
  ArFunctorC<ArActionKeydrive> myRightCB;
  ArFunctorC<ArActionKeydrive> mySpaceCB;
  // action desired
  ArActionDesired myDesired;
  // full speed
  double myTransVelMax;
  // full amount to turn
  double myTurnAmountMax;
  // amount to increment vel by on an up arrow or decrement on a down arrow
  double myVelIncrement;
  // amount to increment turn by on a left arrow or right arrow
  double myTurnIncrement;
  // amount we want to speed up
  double myDeltaVel;
  // amount we want to turn 
  double myTurnAmount;
  // what speed we want to go
  double myDesiredSpeed;
  // if our speeds been reset
  bool mySpeedReset;
};


#endif // ARACTIONKEYDRIVE_H
