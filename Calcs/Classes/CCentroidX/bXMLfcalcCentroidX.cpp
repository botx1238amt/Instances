//----------------------------------------------------------------------------
// File : bXMLfcalcCentroidX.cpp
// Project : MacMap
// Purpose : C++ source file : Calc x centroïd formula class. Return x centroïd of an object.
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

#include "bXMLfcalcCentroidX.h"
#include <MacMapSuite/vx_lib.h>
#include <MacMapSuite/bTrace.h>

// ---------------------------------------------------------------------------
// Constructeur
// ------------
bfcalcCentroidXElement	::bfcalcCentroidXElement(bGenericXMLBaseElement* elt, bGenericMacMapApp* gapp, CFBundleRef bndl ) 
				: bStdXMLCalc(elt,gapp,bndl){
	setclassname("fcalccentroidx");
	_dbval=new bDoubleDBValue;
}

// ---------------------------------------------------------------------------
// Destructeur
// -----------
bfcalcCentroidXElement::~bfcalcCentroidXElement(){
}

// ---------------------------------------------------------------------------
// Constructeur
// ------------
bGenericXMLBaseElement* bfcalcCentroidXElement::create(bGenericXMLBaseElement* elt){
	return(new bfcalcCentroidXElement(elt,_gapp,elt->getbundle()));
}

// ---------------------------------------------------------------------------
// 
// -----------
bool bfcalcCentroidXElement::solve(bStdSolver* ctx){
bGenericGeoElement*	o=ctx->get_object();
	if(!o){
		return(false);
	}
ivertices*			vxs;
	o->getVertices(&vxs);
i2dvertex			ivx;
d2dvertex			dvx;
bGenericType*		tp=_gapp->typesMgr()->get(o->getType());
	switch(tp->kind()){
		case kBaseKindPoint:
		case kBaseKindText:
			ivs_centro(vxs,&ivx);
			break;
		case kBaseKindPolyline:
			ivs_centro_line(vxs,&ivx);
			break;
		case kBaseKindPolygon:
		case kBaseKindRaster:
			ivs_centro_surf(vxs,&ivx);
			break;
	}
	_gapp->locConverter()->convert(&dvx,&ivx);
////trc.msg("%d:%d->%.2f:%.2f",ivx.h,ivx.v,dvx.x,dvx.y);
	_dbval->put(dvx.x);
	return(ctx->add(_dbval));
}

