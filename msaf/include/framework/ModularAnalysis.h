//
// Created by Liture on 2025/1/5.
//

#ifndef MSAF_MODULARANALYSIS_H
#define MSAF_MODULARANALYSIS_H

#include "SVFIR/SVFIR.h"

using namespace SVF;

class ModularAnalysis {

public:
    ModularAnalysis(const SVFFunction *curFun);

    ~ModularAnalysis();

    void run();

    const SVFFunction *getCurFun(const SVFFunction *curFun);
protected:

    ///> process a single basic block
    virtual void beforeProcessBasicBlock(const SVFBasicBlock *bb);
    virtual void processBasicBlock(const SVFBasicBlock *bb);
    virtual void afterProcessBasicBlock(const SVFBasicBlock *bb);

    ///> schedule stmt process
    virtual void beforeProcessStmt(const SVFStmt *stmt);
    virtual void processStmt(const SVFStmt *stmt);
    virtual void afterProcessStmt(const SVFStmt *stmt);

    ///> process all other kinds of statements
    virtual void processAddr(const AddrStmt *addrStmt);
    virtual void processCopy(const CopyStmt *copyStmt);
    virtual void processStore(const StoreStmt *storeStmt);
    virtual void processLoad(const LoadStmt *loadStmt);
    virtual void processGep(const GepStmt *gepStmt);
    virtual void processPhi(const PhiStmt *phiStmt);
    virtual void processSelect(const SelectStmt *selectStmt);
    virtual void processCmp(const CmpStmt *cmpStmt);
    virtual void processBinaryOP(const BinaryOPStmt *binOPStmt);
    virtual void processUnaryOP(const UnaryOPStmt *unaryOPStmt);
    virtual void processBranch(const BranchStmt *branchStmt);

    ///> process call
    virtual void processCall(const CallICFGNode *call);
private:
    ///> current function analyzed
    const SVFFunction *curFun;
};


#endif //MSAF_MODULARANALYSIS_H
