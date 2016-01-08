//----------------------------------------------------------------------------// File : bXMLColorField8.cpp// Project : MacMap// Purpose : C++ source file : 8 color field tag class, used in styles// Author : Benoit Ogier, benoit.ogier@macmap.com//// Copyright (C) 1997-2015 Carte Blanche Conseil.//// This program is free software: you can redistribute it and/or modify// it under the terms of the GNU General Public License as published by// the Free Software Foundation, either version 3 of the License, or// (at your option) any later version.//// This program is distributed in the hope that it will be useful,// but WITHOUT ANY WARRANTY; without even the implied warranty of// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the// GNU General Public License for more details.//// You should have received a copy of the GNU General Public License// along with this program.  If not, see <http://www.gnu.org/licenses/>.//// See the LICENSE.txt file for more information.////----------------------------------------------------------------------------// //----------------------------------------------------------------------------// 02/04/2003 creation.//----------------------------------------------------------------------------#include "bXMLColorField8.h"// ---------------------------------------------------------------------------// Field// ------------// ---------------------------------------------------------------------------// Constructeur// ------------bColorField8Element	::bColorField8Element(bGenericXMLBaseElement* elt, bGenericMacMapApp* gapp, CFBundleRef bndl )					: bStdXMLRenderingElement(elt,gapp,bndl){	setclassname("colorfield8");	setobjectcompliant(true);}// ---------------------------------------------------------------------------// Constructeur// ------------bGenericXMLBaseElement* bColorField8Element::create(bGenericXMLBaseElement* elt){	return(new bColorField8Element(elt,_gapp,elt->getbundle()));}// ---------------------------------------------------------------------------// Destructeur// ------------bColorField8Element::~bColorField8Element(){}// ---------------------------------------------------------------------------// Action// -----------bool bColorField8Element::action(bGenericGraphicContext *ctx){bGenericGeoElement	*geo=ctx->getCurElement();int					color=1;	if(geo){		geo->getValue(_cfvalue,&color);	}	switch(color){		case 1:			ctx->setCyan(0);			ctx->setMagenta(0);			ctx->setYellow(0);			ctx->setBlack(1);			break;		case 2:			ctx->setCyan(0);			ctx->setMagenta(0);			ctx->setYellow(0);			ctx->setBlack(0);			break;		case 3:			ctx->setRed(1);			ctx->setGreen(0);			ctx->setBlue(0);			break;		case 4:			ctx->setRed(0);			ctx->setGreen(1);			ctx->setBlue(0);			break;		case 5:			ctx->setRed(0);			ctx->setGreen(0);			ctx->setBlue(1);			break;		case 6:			ctx->setCyan(1);			ctx->setMagenta(0);			ctx->setYellow(0);			ctx->setBlack(0);			break;		case 7:			ctx->setCyan(0);			ctx->setMagenta(1);			ctx->setYellow(0);			ctx->setBlack(0);			break;		case 8:			ctx->setCyan(0);			ctx->setMagenta(0);			ctx->setYellow(1);			ctx->setBlack(0);			break;		default:			ctx->setCyan(0);			ctx->setMagenta(0);			ctx->setYellow(0);			ctx->setBlack(1);			break;	}	return(true);}