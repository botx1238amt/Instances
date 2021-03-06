//----------------------------------------------------------------------------
// File : bXMLDash.cpp
// Project : MacMap
// Purpose : C++ source file : dash tag class, used in styles
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

#include "bXMLDash.h"
#include <mox_intf/ext_utils.h>
#include <MacMapSuite/bTrace.h>

// ---------------------------------------------------------------------------
// Dash
// ------------
// ---------------------------------------------------------------------------
// Constructeur
// ------------
bDashElement	::bDashElement(bGenericXMLBaseElement* elt, bGenericMacMapApp* gapp, CFBundleRef bndl )
				: bStdXMLLowRenderElement(elt,gapp,bndl){
	setclassname("dash");
	setclasscompliant(true);
	_dsh=NULL;
	_ndsh=0;
}

// ---------------------------------------------------------------------------
// Constructeur
// ------------
bGenericXMLBaseElement* bDashElement::create(bGenericXMLBaseElement* elt){
	return(new bDashElement(elt,_gapp,elt->getbundle()));
}

// ---------------------------------------------------------------------------
// Destructeur
// ------------
bDashElement::~bDashElement(){
}

// ---------------------------------------------------------------------------
// Init
// -----------
void bDashElement::init(void *ctx){
	if(_dsh){
		delete _dsh;
		_dsh=NULL;
	}
	_ndsh=0;
	_last[0]=0;
	bStdXMLLowRenderElement::init(ctx);
	_tp=((bGenericStyle*)ctx)->gettype();
}

// ---------------------------------------------------------------------------
// 
// -----------
bool bDashElement::actionval(	bGenericGraphicContext* ctx,
								bStdXMLValueElement* elt,
								bGenericGeoElement* geo){
//_bTrace_("bDashElement::actionval",true);
char	val[_values_length_max_];
//_tm_(geo->getID());
	elt->getvalue(geo,val);
	if(strlen(val)==0){
//_tw_("(strlen(val)==0)");
//        ctx->setDash(_dsh,_ndsh,val);
bStdXMLValueElement*    eltstd=find_value();
        if(eltstd==NULL){
//_tw_("(eltstd==NULL)");
            val[0]=0;
        }
        else{
            eltstd->getvalue(NULL,val);
        }
//_tm_("default value ="+val);
	}
	if(!strcmp(_last,val)){
//_tm_(_last+" > "+val);
        ctx->setDash(_dsh,_ndsh,val);
		return(true);
	}
    if(_dsh){
		delete _dsh;
	}
    strcpy(_last,"");
    _dsh=NULL;
    _ndsh=0;
    if(!read(val)){
//_te_("Read error for "+val);
        ctx->setDash(_dsh,_ndsh,val);
        return(true);
    }
	strcpy(_last,val);
	ctx->setDash(_dsh,_ndsh,val);
	return(true);
}

// ---------------------------------------------------------------------------
// 
// -----------
bool bDashElement::actionstd(bGenericGraphicContext* ctx){
//_bTrace_("bDashElement::actionstd",true);
char	val[_values_length_max_];
	if(objectcompliant()){
bStdXMLValueElement*	elt=find_value();
		if(elt==NULL){
			return(true);
		}
		elt->getvalue(NULL,val);
	}
	else{
		getvalue(val);
	}
//_tm_(val);
	if(_dsh==NULL){
		if(strlen(val)==0){
            strcpy(_last,"");
			ctx->setDash(NULL,0,"");
            return(true);
		}
		if(!read(val)){
            strcpy(_last,val);
			ctx->setDash(NULL,0,"");
            return(true);
		}
        strcpy(_last,val);
	}
	ctx->setDash(_dsh,_ndsh,val);
    return(true);
}

// ---------------------------------------------------------------------------
// 
// -----------
bool bDashElement::read(char* name){
//_bTrace_("bDashElement::read",true);
//_tm_(name);
	_dsh=GetDash(_gapp,_tp,name,&_ndsh);
//_tm_("dash="+(long)_dsh);
//_tm_("ndash="+(long)_ndsh);
//_tm_("name="+name);
	if(_dsh){
//_tm_("read ok, nb = "+_ndsh);
		return(true);
	}
	return(false);
}
