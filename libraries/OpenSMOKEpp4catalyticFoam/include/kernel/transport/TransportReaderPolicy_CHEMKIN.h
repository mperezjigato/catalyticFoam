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

#ifndef OpenSMOKE_TransportReaderPolicy_CHEMKIN_H
#define	OpenSMOKE_TransportReaderPolicy_CHEMKIN_H

#include <string>
#include <map>
#include "kernel/kinetics/KineticsUtilityFunctions.h"

namespace OpenSMOKE
{
	//!  A class for reading a transport database (from file) in CHEMKIN format
	/*!
		 The purpose of this class is to read a file containing the transport database in CHEMKIN format
	*/

	template<typename Species>
	class TransportReaderPolicy_CHEMKIN 
	{

	public:

		typedef std::map<std::string, Species, OpenSMOKE_Utilities::ciLessLibC> map_species;

		/**
		*@brief Default destructor
		*/
		TransportReaderPolicy_CHEMKIN ();

		/**
		*@brief Default copy destructor
		*/
		TransportReaderPolicy_CHEMKIN (const TransportReaderPolicy_CHEMKIN& orig);

		/**
		*@brief Default destructor
		*/
		virtual ~TransportReaderPolicy_CHEMKIN();

		/**
		*@brief Returns the map of all the species contained in the transport database
		*/
		map_species& species() { return species_; }

		/**
		*@brief Returns the map of all the species contained in the transport database
		*/
		const map_species& species() const { return species_; }

	protected:

		map_species species_;	//!< map of the species in the kinetic scheme

		/**
		*@brief Reads the transport database from a file in ASCII format
		*/
		bool ReadFromASCIIFile(const std::string file_name);
  
	};

}

#endif	/* OpenSMOKE_TransportReaderPolicy_CHEMKIN_H */

