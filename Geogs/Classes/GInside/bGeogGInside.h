//----------------------------------------------------------------------------
// File : bGeogGInside.h
// Project : MacMap
// Purpose : Header file : Inside Geog interface class
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
// 28/01/2005 creation.
//----------------------------------------------------------------------------

#ifndef __bGeogGInside__
#define __bGeogGInside__

//----------------------------------------------------------------------------

#include <std_ext/bStdGeog.h>

//----------------------------------------------------------------------------

enum{
	kGeogGInsideSignature		='GIns',
	kGeogGInsideFullyID			=1,
	kGeogGInsideFullyCmd		='full',
	kGeogGInsidePartlyID		=2,
	kGeogGInsidePartlyCmd		='part',
	kGeogGInsideStrictlyID		=3,
	kGeogGInsideStrictlyCmd		='strc'
};


#define kGeogGInsideMsgFully	"fully"
#define kGeogGInsideMsgPartly	"partly"
#define kGeogGInsideMsgStrictly	"strictly"

#define GInsideSignature		'gins'

//----------------------------------------------------------------------------

class bGeogGInside : public bStdGeog {
	public:		
		bGeogGInside							(	bGenericXMLBaseElement* elt, 
													bGenericMacMapApp* gapp, 
													CFBundleRef bndl);
		virtual ~bGeogGInside					(	);
		virtual bGenericXMLBaseElement* create	(	bGenericXMLBaseElement* elt);

		virtual void open						(	int* flags);
		virtual void close						(	);

		virtual bool event						(	EventRef evt);
		virtual bool edit						(	WindowRef wd, 
													Rect* r);
		virtual void end_edit					(	);
		virtual void hide						(	);
		virtual void show						(	);
		virtual void get_params					(	bArray* arr, 
													int indent);
		virtual void put_params					(	bGenericXMLBaseElement* root);

	protected:
	
	private:
		ControlRef	_cfull;
		ControlRef	_cpart;
		ControlRef	_cstrict;
		bool		_full;
		bool		_strict;
};

//----------------------------------------------------------------------------

#endif
