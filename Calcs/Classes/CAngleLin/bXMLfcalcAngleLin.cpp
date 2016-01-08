//----------------------------------------------------------------------------
// File : bXMLfcalcAngleLin.cpp
// Project : MacMap
// Purpose : C++ source file : Calc anglelin formula class. Return angle between start and end point of a line.
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

#include "bXMLfcalcAngleLin.h"
#include <MacMapSuite/vx_lib.h>
#include <MacMapSuite/bTrace.h>

// ---------------------------------------------------------------------------
// Constructeur
// ------------
bfcalcAngleLinElement	::bfcalcAngleLinElement(bGenericXMLBaseElement* elt, bGenericMacMapApp* gapp, CFBundleRef bndl ) 
					: bStdXMLCalc(elt,gapp,bndl){
	setclassname("fcalcanglelin");
	_dbval=new bDoubleDBValue;
}

// ---------------------------------------------------------------------------
// Destructeur
// -----------
bfcalcAngleLinElement::~bfcalcAngleLinElement(){
}

// ---------------------------------------------------------------------------
// Constructeur
// ------------
bGenericXMLBaseElement* bfcalcAngleLinElement::create(bGenericXMLBaseElement* elt){
	return(new bfcalcAngleLinElement(elt,_gapp,elt->getbundle()));
}

// ---------------------------------------------------------------------------
// 
// -----------
void  bfcalcAngleLinElement::init(void* ctx){
	bStdXMLCalc::init(ctx);
}

// ---------------------------------------------------------------------------
// 
// -----------
bool bfcalcAngleLinElement::solve(bStdSolver* ctx){
bGenericGeoElement*	o=ctx->get_object();
	if(!o){
		return(false);
	}
ivertices*			vxs;
i2dvertex			vx;
	o->getVertices(&vxs);
double	a=vx_angle(&vxs->vx.vx2[0],&vxs->vx.vx2[vxs->nv-1]);
	_dbval->put(rad2deg(a));
	return(ctx->add(_dbval));
}

