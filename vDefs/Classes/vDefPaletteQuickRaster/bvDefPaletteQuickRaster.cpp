//----------------------------------------------------------------------------
// File : bvDefPaletteQuickRaster.cpp
// Project : MacMap
// Purpose : C++ source file : Raster vdef class
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
// 27/06/2012 creation.
//----------------------------------------------------------------------------

#include "bvDefPaletteQuickRaster.h"
#include "bvDefQuickRasterStyle.h"
#include "CocoaStuff.h"
#include <MacMapSuite/bTrace.h>
#include <mox_intf/xmldesc_utils.h>
#include <mox_intf/endian.h>
#include <mox_intf/ext_utils.h>
#include <MacMapSuite/valconv.h>

// ---------------------------------------------------------------------------
// Constructeur
// ------------
bvDefPaletteQuickRaster	::bvDefPaletteQuickRaster(bGenericXMLBaseElement* elt, bGenericMacMapApp* gapp, CFBundleRef bndl) 
						: bvDefPaletteQuick(elt,gapp,bndl){
	setclassname("palettequickRaster");
	strcpy(_stylename,"rasterstyle");
}

// ---------------------------------------------------------------------------
// Destructeur
// -----------
bvDefPaletteQuickRaster::~bvDefPaletteQuickRaster(){
}

// ---------------------------------------------------------------------------
// Constructeur
// ------------
bGenericXMLBaseElement* bvDefPaletteQuickRaster::create(bGenericXMLBaseElement* elt){
	return(new bvDefPaletteQuickRaster(elt,_gapp,elt->getbundle()));
}

// ---------------------------------------------------------------------------
// 
// ------------
bool bvDefPaletteQuickRaster::test(bGenericType* tp){
	if(bStdNSPalettevDef::test(tp)==false){
		return(false);
	}
	if(tp==NULL){
		return(false);
	}
	return((tp->kind()==kBaseKindRaster));
}

// ---------------------------------------------------------------------------
// 
// -----------
void* bvDefPaletteQuickRaster::ccinit(){	
	return(initializeCocoa(getapp(),this));
}

// ---------------------------------------------------------------------------
// 
// ------------
void bvDefPaletteQuickRaster::stl_alloc(){
_bTrace_("bvDefPaletteQuickRaster::stl_alloc()",true);
int						n=_tp->fields()->count_constraints(_fld);
int						k=_tp->fields()->get_constraints_kind(_fld);
int						ib;
bvDefQuickRasterStyle*	stl;
double					cmin,cmax;
	
	for(int i=1;i<=n;i++){
		switch(k){
			case _int:
			case _bool:
				_tp->fields()->get_constraint(_fld,i,&ib);
				cmin=ib;
				if(i==n){
					cmax=cmin+1;
				}
				else{
					_tp->fields()->get_constraint(_fld,i+1,&ib);
					cmax=ib;
				}
				break;
			case _double:
			case _date:
			case _time:
				_tp->fields()->get_constraint(_fld,i,&cmin);
				if(i==n){
					cmax=cmin+1;
				}
				else{
					_tp->fields()->get_constraint(_fld,i+1,&cmax);
				}
				break;
			default:
				cmin=i;
				cmax=i+1;
				break;
		}
		stl=new bvDefQuickRasterStyle(_gapp,_tp,i);
		if(_cmyk){
			stl->_cc=5;
		}
		_styles.add(&stl);
	}
}

// ---------------------------------------------------------------------------
// 
// ------------
void bvDefPaletteQuickRaster::stl_free(){
_bTrace_("bvDefPaletteQuickRaster::stl_free()",true);
bvDefQuickRasterStyle* stl;
	for(int i=1;i<=_styles.count();i++){
		_styles.get(i,&stl);
		delete stl;
	}
	_styles.reset();
}

