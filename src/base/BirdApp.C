#include "BirdApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<BirdApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

BirdApp::BirdApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  BirdApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  BirdApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  BirdApp::registerExecFlags(_factory);
}

BirdApp::~BirdApp() {}

void
BirdApp::registerApps()
{
  registerApp(BirdApp);
}

void
BirdApp::registerObjects(Factory & factory)
{
    Registry::registerObjectsTo(factory, {"BirdApp"});
}

void
BirdApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & action_factory)
{
  Registry::registerActionsTo(action_factory, {"BirdApp"});

  /* Uncomment Syntax parameter and register your new production objects here! */
}

void
BirdApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
BirdApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

void
BirdApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execution flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
BirdApp__registerApps()
{
  BirdApp::registerApps();
}

extern "C" void
BirdApp__registerObjects(Factory & factory)
{
  BirdApp::registerObjects(factory);
}

extern "C" void
BirdApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  BirdApp::associateSyntax(syntax, action_factory);
}

extern "C" void
BirdApp__registerExecFlags(Factory & factory)
{
  BirdApp::registerExecFlags(factory);
}
