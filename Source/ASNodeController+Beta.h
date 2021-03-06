//
//  ASNodeController+Beta.h
//  Texture
//
//  Copyright (c) Facebook, Inc. and its affiliates.  All rights reserved.
//  Changes after 4/13/2017 are: Copyright (c) Pinterest, Inc.  All rights reserved.
//  Licensed under Apache 2.0: http://www.apache.org/licenses/LICENSE-2.0
//

#import <AsyncDisplayKit/ASDisplayNode.h>
#import <AsyncDisplayKit/ASDisplayNode+Subclasses.h> // for ASInterfaceState protocol

/* ASNodeController is currently beta and open to change in the future */
@interface ASNodeController<__covariant DisplayNodeType : ASDisplayNode *> : NSObject <ASInterfaceStateDelegate>

@property (nonatomic, strong /* may be weak! */) DisplayNodeType node;

// Until an ASNodeController can be provided in place of an ASCellNode, some apps may prefer to have
// nodes keep their controllers alive (and a weak reference from controller to node)

@property (nonatomic) BOOL shouldInvertStrongReference;

- (void)loadNode;

// for descriptions see <ASInterfaceState> definition
- (void)nodeDidLoad ASDISPLAYNODE_REQUIRES_SUPER;
- (void)nodeDidLayout ASDISPLAYNODE_REQUIRES_SUPER;

- (void)didEnterVisibleState ASDISPLAYNODE_REQUIRES_SUPER;
- (void)didExitVisibleState  ASDISPLAYNODE_REQUIRES_SUPER;

- (void)didEnterDisplayState ASDISPLAYNODE_REQUIRES_SUPER;
- (void)didExitDisplayState  ASDISPLAYNODE_REQUIRES_SUPER;

- (void)didEnterPreloadState ASDISPLAYNODE_REQUIRES_SUPER;
- (void)didExitPreloadState  ASDISPLAYNODE_REQUIRES_SUPER;

- (void)interfaceStateDidChange:(ASInterfaceState)newState
                      fromState:(ASInterfaceState)oldState ASDISPLAYNODE_REQUIRES_SUPER;

- (void)hierarchyDisplayDidFinish ASDISPLAYNODE_REQUIRES_SUPER;

@end

@interface ASDisplayNode (ASNodeController)

@property(nonatomic, readonly) ASNodeController *nodeController;

@end
