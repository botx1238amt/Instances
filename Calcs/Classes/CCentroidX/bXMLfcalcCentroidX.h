//----------------------------------------------------------------------------
// File : bXMLfcalcCentroidX.h
// Project : MacMap
// Purpose : Header file : Calc x centroïd formula class. Return x centroïd of an object.
// Author : Benoit Ogier, benoit.ogier@macmap.com
//
// Copyright (C) 1997-2015 Carte Blanche Conseil.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// See the LICENSE.txt file for more information.
//
//----------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------
// 01/12/2005 creation.
//----------------------------------------------------------------------------

#ifndef __bXMLfcalcCentroidX__
#define __bXMLfcalcCentroidX__

//----------------------------------------------------------------------------

#include <std_ext/bStdXMLCalc.h>

//----------------------------------------------------------------------------

class bfcalcCentroidXElement : public bStdXMLCalc{
	public:		
		bfcalcCentroidXElement					(	bGenericXMLBaseElement* elt, 
													bGenericMacMapApp* gapp, 
													CFBundleRef bndl );
		virtual ~bfcalcCentroidXElement			(	);
		virtual bGenericXMLBaseElement* create	(	bGenericXMLBaseElement* elt);
		
		virtual bool solve						(	bStdSolver* ctx);
};

//----------------------------------------------------------------------------

#endif
