//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "BirdTestApp.h"
#include "BirdApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<BirdTestApp>()
{
  InputParameters params = validParams<BirdApp>();
  return params;
}

BirdTestApp::BirdTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  BirdApp::registerObjectDepends(_factory);
  BirdApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  BirdApp::associateSyntaxDepends(_syntax, _action_factory);
  BirdApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  BirdApp::registerExecFlags(_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    BirdTestApp::registerObjects(_factory);
    BirdTestApp::associateSyntax(_syntax, _action_factory);
    BirdTestApp::registerExecFlags(_factory);
  }
}

BirdTestApp::~BirdTestApp() {}

void
BirdTestApp::registerApps()
{
  registerApp(BirdApp);
  registerApp(BirdTestApp);
}

void
BirdTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
BirdTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

void
BirdTestApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execute flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
BirdTestApp__registerApps()
{
  BirdTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
BirdTestApp__registerObjects(Factory & factory)
{
  BirdTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
BirdTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  BirdTestApp::associateSyntax(syntax, action_factory);
}

// External entry point for dynamic execute flag loading
extern "C" void
BirdTestApp__registerExecFlags(Factory & factory)
{
  BirdTestApp::registerExecFlags(factory);
}
