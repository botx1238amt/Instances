//----------------------------------------------------------------------------
// File : bXMapCloneDetector.h
// Project : MacMap
// Purpose : Header file : XMap clone detector class
// Author : Benoit Ogier, benoit.ogier@macmap.com
//
// Copyright (C) 2016 Carte Blanche Conseil.
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
// 09/02/2016 creation.
// 09/02/2016 cocoa intf.
//----------------------------------------------------------------------------

#ifndef __bXMapCloneDetector__
#define __bXMapCloneDetector__

//----------------------------------------------------------------------------

#include <std_ext/bStdXMap.h>
#include <std_ext/bXMapStdIntf.h>
#include <Carbon/Carbon.h>

//----------------------------------------------------------------------------

#define kXMapCloneFoundMessageID	"CloneFound"
#define kXMapNoCloneFoundMessageID	"NoCloneFound"

//----------------------------------------------------------------------------

class bXMapCloneDetector : public bStdXMap{
public:
    bXMapCloneDetector                      (	bGenericXMLBaseElement* elt,
                                                bGenericMacMapApp* gapp, 
                                                CFBundleRef bndl);
    virtual ~bXMapCloneDetector             (	);
    virtual bGenericXMLBaseElement* create	(	bGenericXMLBaseElement* elt);
            
    virtual void open						(	int* flags);
    virtual bool edit						(	void* prm);
    
    virtual bool process					(	int msg,
                                                void* prm);
    virtual bool test						(	void* prm);

    virtual void set_infos                  (	clonedetector_prm   prm);
    virtual void get_infos                  (	clonedetector_prm*   prm);

protected:
    virtual bool detect						(	clonedetector_prm* prm);
    virtual bool obj_comp					(	bGenericGeoElement* oa,
                                                bGenericGeoElement* ob,
                                                clonedetector_prm* prm);

private:
    clonedetector_prm	_prm;

};

//----------------------------------------------------------------------------

#endif