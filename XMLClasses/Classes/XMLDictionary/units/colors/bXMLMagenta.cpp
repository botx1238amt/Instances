//----------------------------------------------------------------------------
// File : bXMLMagenta.cpp
// Project : MacMap
// Purpose : C++ source file : magenta color tag class, used in styles
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
// 02/04/2003 creation.
//----------------------------------------------------------------------------

#include "bXMLMagenta.h"

// ---------------------------------------------------------------------------
// Magenta
// ------------
// ---------------------------------------------------------------------------
// Constructeur
// ------------
bMagentaElement	::bMagentaElement(bGenericXMLBaseElement* elt, bGenericMacMapApp* gapp, CFBundleRef bndl )
				: bStdXMLLowRenderElement(elt,gapp,bndl){
	setclassname("magenta");
	setclasscompliant(true);
}

// ---------------------------------------------------------------------------
// Constructeur
// ------------
bGenericXMLBaseElement* bMagentaElement::create(bGenericXMLBaseElement* elt){
	return(new bMagentaElement(elt,_gapp,elt->getbundle()));
}

// ---------------------------------------------------------------------------
// Destructeur
// ------------
bMagentaElement::~bMagentaElement(){
}

// ---------------------------------------------------------------------------
// 
// -----------
bool bMagentaElement::actionval(	bGenericGraphicContext* ctx,
								bStdXMLValueElement* elt,
								bGenericGeoElement* geo){
double	x;
	elt->getvalue(geo,&x);
	if((x>=0)&&(x<=1)){
		ctx->setMagenta(x);
		return(true);
	}
	return(false);
}

// ---------------------------------------------------------------------------
// 
// -----------
bool bMagentaElement::actionstd(bGenericGraphicContext* ctx){
double	x;
char	val[_values_length_max_];
	if(objectcompliant()){
bStdXMLValueElement*	elt=find_value();
		if(elt==NULL){
			getvalue(val);
			if(strlen(val)==0){
				return(true);
			}
			x=atof(val);
		}
		else{
			elt->getvalue(NULL,&x);
		}
	}
	else{
		getvalue(val);
		if(strlen(val)==0){
			return(false);
		}
		x=atof(val);
	}
	if((x>=0)&&(x<=1)){
		ctx->setMagenta(x);
		return(true);
	}
	return(objectcompliant());
}

