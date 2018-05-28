//----------------------------------------------------------------------------// File : bXMLVisible.cpp// Project : MacMap// Purpose : C++ source file : layer visibility tag class, used in views// Author : Benoit Ogier, benoit.ogier@macmap.com//// Copyright (C) 1997-2015 Carte Blanche Conseil.//// This program is free software: you can redistribute it and/or modify// it under the terms of the GNU General Public License as published by// the Free Software Foundation, either version 3 of the License, or// (at your option) any later version.//// This program is distributed in the hope that it will be useful,// but WITHOUT ANY WARRANTY; without even the implied warranty of// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the// GNU General Public License for more details.//// You should have received a copy of the GNU General Public License// along with this program.  If not, see <http://www.gnu.org/licenses/>.//// See the LICENSE.txt file for more information.////----------------------------------------------------------------------------// Classe de base pour lecture de paramétrages au format XML//----------------------------------------------------------------------------// 22/10/2003 creation.//----------------------------------------------------------------------------#include "bXMLVisible.h"// ---------------------------------------------------------------------------// Visible// ------------// ---------------------------------------------------------------------------// Constructeur// ------------bVisibleElement	::bVisibleElement(bGenericXMLBaseElement* elt, bGenericMacMapApp* gapp, CFBundleRef bndl ) 				: bStdXMLLayerElement(elt,gapp,bndl){	setclassname("visible");}// ---------------------------------------------------------------------------// Constructeur// ------------bGenericXMLBaseElement* bVisibleElement::create(bGenericXMLBaseElement* elt){	return(new bVisibleElement(elt,(bGenericMacMapApp*)elt->getapp(),elt->getbundle()));}// ---------------------------------------------------------------------------// Destructeur// ------------bVisibleElement::~bVisibleElement(){}// ---------------------------------------------------------------------------// Init// ------------void bVisibleElement::init(void* ctx){//    ((bGenericLayerAccessContext*)ctx)->setvisible(atoi(_cfvalue));    ((bGenericLayersMgr*)ctx)->setvisible(atoi(_cfvalue));}