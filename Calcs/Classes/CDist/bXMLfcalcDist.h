//----------------------------------------------------------------------------
// File : bXMLfcalcDist.h
// Project : MacMap
// Purpose : Header file : Calc distance formula class. Return distance between an object and contrasts centroïds.
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
// 09/12/2005 creation.
//----------------------------------------------------------------------------

#ifndef __bXMLfcalcDist__
#define __bXMLfcalcDist__

//----------------------------------------------------------------------------

#include <std_ext/bStdXMLCalc.h>

//----------------------------------------------------------------------------

class bfcalcDistElement : public bStdXMLCalc{
	public:		
		bfcalcDistElement						(	bGenericXMLBaseElement* elt, 
													bGenericMacMapApp* gapp, 
													CFBundleRef bndl );
		virtual ~bfcalcDistElement				(	);
		virtual bGenericXMLBaseElement* create	(	bGenericXMLBaseElement* elt);
		
		virtual bool solve						(	bStdSolver* ctx);
};

//----------------------------------------------------------------------------

#endif