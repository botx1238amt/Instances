//----------------------------------------------------------------------------
// File : VarWindowController.mm
// Project : MacMap
// Purpose : Objective C++ source file : Variables/Constants XMapBox window controller
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
// 20/01/2015 creation.
//----------------------------------------------------------------------------

#import "VarWindowController.h"
#import "bXBoxVar.h"
#import "CocoaStuff.h"

#import <MacMapSuite/bTrace.h>

// ---------------------------------------------------------------------------
// 
// ------------
@implementation VarPanel

// ---------------------------------------------------------------------------
// 
// ------------
@end

// ---------------------------------------------------------------------------
// 
// ------------
@implementation VarWindowController

// ---------------------------------------------------------------------------
// 
// ------------
-(id)init{
_bTrace_("[VarWindowController init]",true);
	self=[super init];
	if(self){
	}
    return self;
}

// ---------------------------------------------------------------------------
// 
// ------------
-(void)dealloc{
_bTrace_("[VarWindowController dealloc]",true);
_tm_((void*)self);
	[super dealloc];
}

// ---------------------------------------------------------------------------
// 
// ------------
-(void)awakeFromNib{
    [super awakeFromNib];
bGenericMacMapApp* gapp=(bGenericMacMapApp*)_ext->getapp();
    _mgr=gapp->varMgr();
    _xsign=kXMLSubClassExtVar;

bGenericExt* x=gapp->xmapMgr()->find('VarE');
    if(x==NULL){
        [_add_btn setEnabled:NO];
        [_edt_btn setEnabled:NO];
    }
}

// ---------------------------------------------------------------------------
// 
// ------------
-(void)close{
_bTrace_("[VarWindowController close]",true);
_tm_((void*)self);
	[super close];
}

#pragma mark ---- Actions ----
// ---------------------------------------------------------------------------
//
// ------------
-(IBAction)doAdd:(id)sender{
_bTrace_("[VarWindowController doAdd]",true);
bGenericMacMapApp*
    gapp=(bGenericMacMapApp*)_ext->getapp();
bGenericExt* x=gapp->xmapMgr()->find('VarE');
    if(x==NULL){
        return;
    }
    x->edit(NULL);
    [_mgr_viw reloadData];
}

// ---------------------------------------------------------------------------
//
// ------------
-(IBAction)doEdit:(id)sender{
_bTrace_("[VarWindowController doEdit]",true);
NSInteger rowNumber=[_mgr_viw selectedRow];
_tm_(rowNumber);
    if(rowNumber==-1){
        return;
    }
    
bGenericMacMapApp*
    gapp=(bGenericMacMapApp*)_ext->getapp();
bGenericExt* ext=_mgr->get(rowNumber+1);
    if(ext==NULL){
        return;
    }
bGenericExt* x=gapp->xmapMgr()->find('VarE');
    if(x==NULL){
        return;
    }
    x->edit(ext);
    [_mgr_viw reloadData];
}

#pragma mark ---- Update Intf ----
// ---------------------------------------------------------------------------
//
// -----------
-(void)updateUI{
bGenericMacMapApp*
    gapp=(bGenericMacMapApp*)_ext->getapp();
bGenericExt* ext=gapp->xmapMgr()->find('VarE');
    
NSInteger rowNumber=[_mgr_viw selectedRow];
    [_rmv_btn setEnabled:(rowNumber>-1)];
    [_edt_btn setEnabled:(rowNumber>-1)&&(ext!=NULL)];
    [_dup_btn setEnabled:(rowNumber>-1)];
}

// ---------------------------------------------------------------------------
// 
// ------------
@end

#pragma mark ---- CPP/Carbon Entry Point ----
// ---------------------------------------------------------------------------
// 
// ------------
void* initializeCocoa(void* gapp, 
					  void* ext) {
VarWindowController	*controller;
NSAutoreleasePool   *localPool;
	
    localPool=[[NSAutoreleasePool alloc] init];   
    controller=[[VarWindowController alloc] init];
    [controller setExt:(bStdNSXBox*)ext];
    [localPool release];
    return((void*)controller);
}

