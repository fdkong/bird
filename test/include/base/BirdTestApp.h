//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef BIRDTESTAPP_H
#define BIRDTESTAPP_H

#include "MooseApp.h"

class BirdTestApp;

template <>
InputParameters validParams<BirdTestApp>();

class BirdTestApp : public MooseApp
{
public:
  BirdTestApp(InputParameters parameters);
  virtual ~BirdTestApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
  static void registerExecFlags(Factory & factory);
};

#endif /* BIRDTESTAPP_H */
