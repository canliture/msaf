//
// Created by Liture on 2025/1/5.
//

#include "framework/ModularAnalysis.h"

void ModularAnalysis::run()
{
    const std::vector<const SVFBasicBlock*>& bbList = curFun->getBasicBlockList();
    for (const SVFBasicBlock *bb : bbList)
    {
        beforeProcessBasicBlock(bb);
        processBasicBlock(bb);
        afterProcessBasicBlock(bb);
    }
}

void ModularAnalysis::beforeProcessBasicBlock(const SVFBasicBlock *bb)
{
    const std::vector<const ICFGNode*>& cfgNodeList = bb->getICFGNodeList();
    for (const ICFGNode *cfgNode : cfgNodeList)
    {
        const ICFGNode::SVFStmtList& stmtList = cfgNode->getSVFStmts();
        for (const SVFStmt *stmt : stmtList)
        {
            beforeProcessStmt(stmt);
            processStmt(stmt);
            afterProcessStmt(stmt);
        }
    }
}

void ModularAnalysis::beforeProcessStmt(const SVFStmt *stmt)
{

}

void ModularAnalysis::afterProcessStmt(const SVFStmt *stmt)
{

}

void ModularAnalysis::processBasicBlock(const SVFBasicBlock *bb)
{

}

void ModularAnalysis::afterProcessBasicBlock(const SVFBasicBlock *bb)
{

}

void ModularAnalysis::processStmt(const SVFStmt *stmt)
{
    if (const AddrStmt *addrStmt = SVFUtil::dyn_cast<AddrStmt>(stmt))
    {
        processAddr(addrStmt);
    }
    else if (const CopyStmt *copyStmt = SVFUtil::dyn_cast<CopyStmt>(stmt))
    {
        processCopy(copyStmt);
    }
    else if (const StoreStmt *storeStmt = SVFUtil::dyn_cast<StoreStmt>(stmt))
    {
        processStore(storeStmt);
    }
    else if (const LoadStmt *loadStmt = SVFUtil::dyn_cast<LoadStmt>(stmt))
    {
        processLoad(loadStmt);
    }
    else if (const GepStmt *gepStmt = SVFUtil::dyn_cast<GepStmt>(stmt))
    {
        processGep(gepStmt);
    }
    else if (const PhiStmt *phiStmt = SVFUtil::dyn_cast<PhiStmt>(stmt))
    {
        processPhi(phiStmt);
    }
    else if (const SelectStmt *selectStmt = SVFUtil::dyn_cast<SelectStmt>(stmt))
    {
        processSelect(selectStmt);
    }
    else if (const CmpStmt *cmpStmt = SVFUtil::dyn_cast<CmpStmt>(stmt))
    {
        processCmp(cmpStmt);
    }
    else if (const BinaryOPStmt *binOpStmt = SVFUtil::dyn_cast<BinaryOPStmt>(stmt))
    {
        processBinaryOP(binOpStmt);
    }
    else if (const UnaryOPStmt *unaryOpStmt = SVFUtil::dyn_cast<UnaryOPStmt>(stmt))
    {
        processUnaryOP(unaryOpStmt);
    }
    else if (const BranchStmt *branchStmt = SVFUtil::dyn_cast<BranchStmt>(stmt))
    {
        processBranch(branchStmt);
    }
}

void ModularAnalysis::processAddr(const AddrStmt *addrStmt)
{

}

void ModularAnalysis::processCopy(const CopyStmt *copyStmt)
{

}

void ModularAnalysis::processStore(const StoreStmt *storeStmt)
{

}

void ModularAnalysis::processLoad(const LoadStmt *loadStmt)
{

}

void ModularAnalysis::processGep(const GepStmt *gepStmt)
{

}

void ModularAnalysis::processPhi(const PhiStmt *phiStmt)
{

}

void ModularAnalysis::processSelect(const SelectStmt *selectStmt)
{

}

void ModularAnalysis::processCmp(const CmpStmt *cmpStmt)
{

}

void ModularAnalysis::processBinaryOP(const BinaryOPStmt *binOPStmt)
{

}

void ModularAnalysis::processUnaryOP(const UnaryOPStmt *unaryOPStmt)
{

}

void ModularAnalysis::processBranch(const BranchStmt *branchStmt)
{

}

void ModularAnalysis::processCall(const CallICFGNode *call)
{

}
