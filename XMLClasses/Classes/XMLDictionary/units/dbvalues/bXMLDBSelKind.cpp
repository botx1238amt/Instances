//----------------------------------------------------------------------------
// File : bXMLDBSelKind.cpp
// Project : MacMap
// Purpose : C++ source file : selection kind tag class, used in selection solvers
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
// 22/03/2004 creation.
//----------------------------------------------------------------------------

#include "bXMLDBSelKind.h"
#include <mox_intf/bSelectSolver.h>

// ---------------------------------------------------------------------------
// Constructeur
// ------------
bDBSelKindElement	::bDBSelKindElement(bGenericXMLBaseElement* elt, bGenericMacMapApp* gapp, CFBundleRef bndl ) 
					: bStdXMLFormulaElement(elt,gapp,bndl){
	setclassname("dbselkind");
}

// ---------------------------------------------------------------------------
// Destructeur
// -----------
bDBSelKindElement::~bDBSelKindElement(){
}

// ---------------------------------------------------------------------------
// Constructeur
// ------------
bGenericXMLBaseElement* bDBSelKindElement::create(bGenericXMLBaseElement* elt){
	return(new bDBSelKindElement(elt,_gapp,elt->getbundle()));
}

// ---------------------------------------------------------------------------
// 
// -----------
void  bDBSelKindElement::init(void* ctx){
//	bStdXMLFormulaElement::init(ctx);
	((bSelectSolver*)ctx)->set_select_kind(atoi(_cfvalue));
}

// ---------------------------------------------------------------------------
// 
// -----------
bool bDBSelKindElement::solve(bStdSolver* ctx){
	return(true);
}

// ---------------------------------------------------------------------------
// 
// -----------
void bDBSelKindElement::reset(bStdSolver* ctx){
}