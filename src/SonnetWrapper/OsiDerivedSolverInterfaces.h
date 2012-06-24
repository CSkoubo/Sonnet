// Copyright (C) 2011, Jan-Willem Goossens 
// All Rights Reserved.
// This code is licensed under the terms of the Eclipse Public License (EPL).

#pragma once

#include <OsiClpSolverInterface.hpp>		// check via ClpSimplex_H (?)
#include <OsiCbcSolverInterface.hpp>		// check via ClpSimplex_H (?)
//#include <OsiVolSolverInterface.hpp>	
#ifdef USE_CPLEX
#include <OsiCpxSolverInterface.hpp>		// check via CPX_VERSION
#endif

#include "OsiSolverInterface.h"
#include "CbcModel.h"
#include "CbcStrategy.h"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace COIN
{
	//////////////////////////////////////////////////////
	///// OsiClpSolverInterface
	//////////////////////////////////////////////////////
	public ref class OsiClpSolverInterface : public OsiSolverInterfaceGeneric<::OsiClpSolverInterface>
	{
	public:
		OsiClpSolverInterface() { }
#ifdef SONNET_LEANLOADPROBLEM
		void OsiClpSolverInterface::LeanLoadProblemInit(int n, int m, int nz, 
			int*&Cst, int *&Clg, int *&Rnr, double *&Elm, 
			double*&l, double*&u, double *& c, double*&bl, double*&bu);
		void LeanLoadProblem(int n, int m, int nz, 
			int*&Cst, int *&Clg, int *&Rnr, double *&Elm, 
			double*&l, double*&u, double *& c, double*&bl, double*&bu);
#endif
	};

	//////////////////////////////////////////////////////
	///// OsiCbcSolverInterface
	//////////////////////////////////////////////////////
	public ref class OsiCbcSolverInterface : public OsiSolverInterfaceGeneric<::OsiCbcSolverInterface>
	{
	public:
		OsiCbcSolverInterface() { }

		// this is NOT a copy constructor
		OsiCbcSolverInterface(OsiSolverInterface ^solver, CbcStrategy ^ strategy)
		{
			Base = new ::OsiCbcSolverInterface(solver->Base, (strategy != nullptr)?strategy->Base:nullptr);
		}

		// this is NOT a copy constructor
		OsiCbcSolverInterface(OsiSolverInterface ^solver)
		{
			Base = new ::OsiCbcSolverInterface(solver->Base, nullptr);
		}

		/// Get pointer to Cbc model
		CbcModel ^ getModelPtr() 
		{
			return gcnew CbcModel(Base->getModelPtr());
		}


		void resetModelToReferenceSolver();
		void saveModelReferenceSolver();

	protected:
		property ::OsiCbcSolverInterface * Derived 
		{
			::OsiCbcSolverInterface * get() 
			{ 
				return dynamic_cast<::OsiCbcSolverInterface*>(Base); 
			} 
		}
	};

	////////////////////////////////////////////////////////
	/////// OsiVolSolverInterface
	////////////////////////////////////////////////////////
	//public ref class OsiVolSolverInterface : public OsiSolverInterface
	//{
	//public:
	//	OsiVolSolverInterface();
	//};

#ifdef USE_CPLEX

	//////////////////////////////////////////////////////
	///// OsiCpxSolverInterface
	//////////////////////////////////////////////////////
	public ref class OsiCpxSolverInterface : public OsiSolverInterfaceGeneric<::OsiCpxSolverInterface>
	{
	public:
		OsiCpxSolverInterface();
	};
#endif
}