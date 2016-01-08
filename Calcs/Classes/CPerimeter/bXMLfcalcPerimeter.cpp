//----------------------------------------------------------------------------
// File : bXMLfcalcPerimeter.cpp
// Project : MacMap
// Purpose : C++ source file : Calc perimeter formula class. Return perimeter of a polygon.
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
// 05/01/2007 creation.
//----------------------------------------------------------------------------

#include "bXMLfcalcPerimeter.h"
#include <MacMapSuite/vx_lib.h>
#include <mox_intf/ext_utils.h>

// ---------------------------------------------------------------------------
// Constructeur
// ------------
bfcalcPerimeterElement	::bfcalcPerimeterElement(bGenericXMLBaseElement* elt, bGenericMacMapApp* gapp, CFBundleRef bndl ) 
						: bStdXMLCalc(elt,gapp,bndl){
	setclassname("fcalcperimeter");
	_dbval=new bDoubleDBValue;
}

// ---------------------------------------------------------------------------
// Destructeur
// -----------
bfcalcPerimeterElement::~bfcalcPerimeterElement(){
}

// ---------------------------------------------------------------------------
// Constructeur
// ------------
bGenericXMLBaseElement* bfcalcPerimeterElement::create(bGenericXMLBaseElement* elt){
	return(new bfcalcPerimeterElement(elt,_gapp,elt->getbundle()));
}

// ---------------------------------------------------------------------------
// 
// -----------
bool bfcalcPerimeterElement::solve(bStdSolver* ctx){
bGenericGeoElement*	o=ctx->get_object();
	if(!o){
		return(false);
	}
ivertices*			vxs;
	o->getVertices(&vxs);
	_dbval->put(Measure_i2d(_gapp,ivs_length(vxs)));
	return(ctx->add(_dbval));
}

