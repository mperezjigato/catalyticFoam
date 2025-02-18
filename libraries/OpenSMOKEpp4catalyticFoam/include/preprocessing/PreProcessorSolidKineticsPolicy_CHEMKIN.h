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

#ifndef OpenSMOKE_PreProcessorSolidKineticsPolicy_CHEMKIN_H
#define	OpenSMOKE_PreProcessorSolidKineticsPolicy_CHEMKIN_H

#include "kernel/thermo/InputFileCHEMKIN.h"

namespace OpenSMOKE
{
	//!  Class to preprocess a kinetic mechanism provided in CHEMKIN format
	/*!
		 This class preprocess a kinetic mechanism in CHEMKIN format (ASCII format).
		 The input file must strictly respect the CHEMKIN syntax rules. In the current
		 version, this class provides the possibility to correct manage the following 
		 key-words (in alphabetical order): CHEB, DUP, FORD, HIGH, LOW, 
		 PCHEB, PLOG, REV, RORD, SRI, TCHEB, TROE, UNITS. Third body reactions and
		 pressure dependent reactions are allowed too. The following options are 
		 not currently available and they will be provided in the next releases:
		 COLLEFF, EXCI, FIT1, JAN, LT, MOME, RLT, TDEP, USRPROG, XSMI.
	*/

	template<typename Reactions>
	class PreProcessorSolidKineticsPolicy_CHEMKIN
	{
	public:

		typedef std::vector<ReactionPolicy_Solid_CHEMKIN> vector_reactions;

		/**
		* Default constructor
		*/
		PreProcessorSolidKineticsPolicy_CHEMKIN();

		/**
		* Copy constructor
		*/
		PreProcessorSolidKineticsPolicy_CHEMKIN(const PreProcessorSolidKineticsPolicy_CHEMKIN& orig);

		/**
		* Default destructor
		*/
		virtual ~PreProcessorSolidKineticsPolicy_CHEMKIN();
	
		/**
		*@brief This function returns the vector containg the list of reactions
		*@return the vector containing the list of reactions
		*/
		std::vector<vector_reactions>& reactions() { return reactions_; }

		/**
		*@brief This function returns the vector containg the list of reactions
		*@return the vector containing the list of reactions
		*/
		const std::vector<vector_reactions>& reactions() const { return reactions_; }

		/**
		*@brief This function returns the vector containg the list of site species
		*@return the vector containing the list of site species
		*/
		const std::vector<std::string>& names_solid_species() const { return names_solid_species_; }

		/**
		*@brief This function returns the vector containg the list of all the additional species 
		*@return the vector containing the list of site species
		*/
		const std::vector<std::string>& names_additional_species() const { return names_solid_species_; }

		/**
		* Reads only the list of species and elements from the file containing the kinetic
		  mechanism in CHEMKIN format. This operation is needed to correctly preprocess the
		  transport and thermodynamic data.
		*/
		bool ReadFromASCIIFile(const std::string file_name);

		/**
		* Reads the whole file containing the kinetic mechanism in CHEMKIN format. Each
		  reaction is parsed and checked in order to find errors about the stoichiometry.
		  This operation requires the knowledge of the atomic composition for every
		  chemical species and this must be provided by the thermodynamic preprocessor.
		*/
		template<typename PreProcessor>
		bool KineticsFromASCIIFile(AtomicCompositionTable& atomicComposition, const PreProcessor& preprocessor_kinetics, std::ostream& flog);
		
		/**
		* Writes the preprocessed kinetic file in a old-style format which can be read 
		  by a previous version of OpenSMOKE. This function has been kept only for 
		  compatibility reasons with previous versions.
		*/
		bool WriteASCIIFileOldStyle(const std::string file_name) const;

		/**
		* Writes the preprocessed kinetic file in ASCII format (obsolete, TOREMOVE)
		*/
		bool WriteASCIIFile(const std::string file_name) const;

		/**
		* Writes the preprocessed kinetic file in XML format
		*/
		bool WriteXMLFile(std::stringstream& xml_string) const;

		/**
		* Writes a short summary of the pre-processed kinetic scheme
		*/
		template<typename Thermodynamics>
		void WriteShortSummaryOnASCIIFile(const std::string file_name, Thermodynamics& thermodynamics) const;



	protected:

		InputFileCHEMKIN* myKinetics;								//!< file containing the kinetic mechanism in CHEMKIN format 
		std::vector< std::vector<unsigned int> > reaction_lines;	//!< list of lines referring to a reaction   

		std::vector<unsigned int> iMaterialLines;					//!< indices of lines referring to a material
		std::vector< std::vector<unsigned int> > iReactionLines;	//!< indices of lines referring to a reaction 
		unsigned int number_of_materials_;							//!< number of materials 
		std::vector<std::string> names_of_materials_;				//!< names of materials 

		std::vector<std::vector<std::string> >	solid_species_;				//!< structured map of solid species names
		std::vector<std::vector<unsigned int> >	solid_species_indices_;		//!< structured map of solid species indices
		std::vector<std::string>				names_solid_species_;		//!< svector of solid species indices

		std::vector< vector_reactions > reactions_;				//!< list of reactions in the kinetic scheme
		std::vector<std::string> names_species_;				//!< list of species in the kinetic scheme
		std::map<std::string, unsigned int> map_of_species;		//!< map of species in the kinetic scheme

		/**
		* Writes the stoichiometric data in a format which can be used by the KineticsMap_CHEMKIN
		*/			
		bool WriteStoichiometricDataOnASCIIFile(std::ostream& fOutput, const unsigned int kk) const;

		/**
		* Writes the sreaction orders in a format which can be used by the KineticsMap_CHEMKIN (only if the
		  reaction orders are different from the stoichiometric coefficients)
		*/	
		bool WriteReactionOrdersOnASCIIFile(std::ostream& fOutput, const unsigned int kk) const;
	};

}

#include "PreProcessorSolidKineticsPolicy_CHEMKIN.hpp"

#endif	/* OpenSMOKE_PreProcessorSolidKineticsPolicy_CHEMKIN_H */

