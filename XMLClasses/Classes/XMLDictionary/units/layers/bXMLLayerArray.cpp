//----------------------------------------------------------------------------
// File : bXMLLayerArray.cpp
// Project : MacMap
// Purpose : C++ source file : layer array tag class, used in views
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
// Classe pour lecture des param FLOAT au format XML
//----------------------------------------------------------------------------
// 02/04/2003 creation.
//----------------------------------------------------------------------------

#include "bXMLLayerArray.h"

// ---------------------------------------------------------------------------
// Layer
// ------------
// ---------------------------------------------------------------------------
// Constructeur
// ------------
bLayerArrayElement	::bLayerArrayElement(bGenericXMLBaseElement* elt, bGenericMacMapApp* gapp, CFBundleRef bndl ) 
					: bStdXMLLayerElement(elt,gapp,bndl){
	setclassname("layerarray");
}

// ---------------------------------------------------------------------------
// Constructeur
// ------------
bGenericXMLBaseElement* bLayerArrayElement::create(bGenericXMLBaseElement* elt){
	return(new bLayerArrayElement(elt,_gapp,elt->getbundle()));
}

// ---------------------------------------------------------------------------
// Destructeur
// ------------
bLayerArrayElement::~bLayerArrayElement(){
}

// ---------------------------------------------------------------------------
// Init
// ------------
void bLayerArrayElement::init(void* ctx){
	((bGenericLayerAccessContext*)ctx)->setarray(this);
	bStdXMLLayerElement::init(ctx);
}
