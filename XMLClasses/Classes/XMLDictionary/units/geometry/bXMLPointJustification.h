//----------------------------------------------------------------------------
// File : bXMLPointJustification.h
// Project : MacMap
// Purpose : Header file : justify on coordinate tag class, used in styles
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
// 12/06/2006 creation.
//----------------------------------------------------------------------------

#ifndef __bPointJustificationElement__
#define __bPointJustificationElement__

//----------------------------------------------------------------------------

#include <std_ext/bStdXMLLowRenderElement.h>
#include <mox_intf/CGUtils.h>

//----------------------------------------------------------------------------

class bPointJustificationElement : public bStdXMLLowRenderElement{
	public:
		bPointJustificationElement 				(	bGenericXMLBaseElement* elt, 
													bGenericMacMapApp* gapp, 
													CFBundleRef bndl );
		virtual ~bPointJustificationElement  	(	);
		virtual bGenericXMLBaseElement* create	(	bGenericXMLBaseElement* elt);
		
		virtual bool actionstd					(	bGenericGraphicContext* ctx);
		virtual bool actionval					(	bGenericGraphicContext* ctx,
													bStdXMLValueElement* elt,
													bGenericGeoElement* geo);
		
	protected:
		bool align								(	bGenericGraphicContext *ctx);
		bool justify							(	bGenericGraphicContext *ctx);

	private:
		double	_val;
};

//----------------------------------------------------------------------------

#endif