/*----------------------------------------------------------------------*\
|    ___                   ____  __  __  ___  _  _______                  |
|   / _ \ _ __   ___ _ __ / ___||  \/  |/ _ \| |/ / ____| _     _         |
|  | | | | '_ \ / _ \ '_ \\___ \| |\/| | | | | ' /|  _| _| |_ _| |_       |
|  | |_| | |_) |  __/ | | |___) | |  | | |_| | . \| |__|_   _|_   _|      |
|   \___/| .__/ \___|_| |_|____/|_|  |_|\___/|_|\_\_____||_|   |_|        |
|        |_|                                                              |
|                                                                         |
|   Author: Alberto Cuoci <alberto.cuoci@polimi.it>                       |
|   CRECK Modeling Group <http://creckmodeling.chem.polimi.it>            |
|   Department of Chemistry, Materials and Chemical Engineering           |
|   Politecnico di Milano                                                 |
|   P.zza Leonardo da Vinci 32, 20133 Milano                              |
|                                                                         |
|-------------------------------------------------------------------------|
|                                                                         |
|   This file is part of OpenSMOKE++ framework.                           |
|                                                                         |
|	License                                                               |
|                                                                         |
|   Copyright(C) 2014, 2013, 2012  Alberto Cuoci                          |
|   OpenSMOKE++ is free software: you can redistribute it and/or modify   |
|   it under the terms of the GNU General Public License as published by  |
|   the Free Software Foundation, either version 3 of the License, or     |
|   (at your option) any later version.                                   |
|                                                                         |
|   OpenSMOKE++ is distributed in the hope that it will be useful,        |
|   but WITHOUT ANY WARRANTY; without even the implied warranty of        |
|   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         |
|   GNU General Public License for more details.                          |
|                                                                         |
|   You should have received a copy of the GNU General Public License     |
|   along with OpenSMOKE++. If not, see <http://www.gnu.org/licenses/>.   |
|                                                                         |
\*-----------------------------------------------------------------------*/

#ifndef OpenSMOKE_KineticsMap_H
#define OpenSMOKE_KineticsMap_H

#include "math/OpenSMOKEClass.h"
#include "math/OpenSMOKEVector.h"

namespace OpenSMOKE
{
	//!  A class to provide a common interface to kinetic mapsfor the evaluation of reaction and formation rates
	/*!
			This class provides a common interface to kinetic mapsfor the evaluation of reaction and formation rates
	*/

	class KineticsMap
	{
	
	public:

		/**
		* Sets the temperature (in K)
		*/
		virtual void SetTemperature(const double& T) = 0;

		/**
		* Sets the pressure (in Pa)
		*/
		virtual void SetPressure(const double& P) = 0;

		/**
		* @brief Returns the number of reactions
		*/
		unsigned int NumberOfReactions() const { return number_of_reactions_; }


	protected:

		unsigned int number_of_species_;		//!< number of species
		unsigned int number_of_reactions_;		//!< total number of reactions

		double T_;									//!< double of temperatures
		double uT_;									//!< double of reciprocal of temperatures
		double logT_;								//!< double of log of temperatures
		double P_;									//!< double of pressures

		double T_old_;								//!< double of temperatures (previous values)
		double P_old_;								//!< double of pressures (previous values)
	};
}

#endif // OpenSMOKE_KineticsMap_H