/*
* Copyright 2018-2019 Redis Labs Ltd. and Contributors
*
* This file is available under the Apache License, Version 2.0,
* modified with the Commons Clause restriction.
*/

#ifndef __OP_COND_VAR_LEN_TRAVERSE_H
#define __OP_COND_VAR_LEN_TRAVERSE_H

#include "op.h"
#include "../../graph/graph.h"
#include "../../algorithms/all_paths.h"
#include "../../arithmetic/algebraic_expression.h"

/* OP Traverse */
typedef struct {
    OpBase op;
    Graph *g;
    AlgebraicExpression *ae;
    int srcNodeIdx;                 /* Node set by operation. */
    int destNodeIdx;                /* Node set by operation. */
    int *relationIDs;               /* Relation(s) we're traversing. */
    int relationIDsCount;           /* Length of relationIDs. */
    GRAPH_EDGE_DIR traverseDir;     /* Traverse direction. */
    unsigned int minHops;           /* Maximum number of hops to perform. */
    unsigned int maxHops;           /* Maximum number of hops to perform. */        
    AllPathsCtx *allPathsCtx;
    Record r;
} CondVarLenTraverse;

OpBase* NewCondVarLenTraverseOp(AlgebraicExpression *ae, unsigned int minHops, unsigned int maxHops, Graph *g);
Record CondVarLenTraverseConsume(OpBase *opBase);
OpResult CondVarLenTraverseReset(OpBase *ctx);
void CondVarLenTraverseFree(OpBase *ctx);
#endif
